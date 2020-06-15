# $NetBSD: options.mk,v 1.1 2020/06/15 15:11:50 scole Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.RE_flex
PKG_SUPPORTED_OPTIONS=	cpu-optimization doxygen examples
PKG_SUGGESTED_OPTIONS=	cpu-optimization

.include "../../mk/bsd.options.mk"

# XXX don't build with cpu optimizations detected during configure
.if empty(PKG_OPTIONS:Mcpu-optimization)
CONFIGURE_ARGS+=	--disable-avx
CONFIGURE_ARGS+=	--disable-sse2
CONFIGURE_ARGS+=	--disable-neon
.endif

# build and install html docs
PLIST_VARS+=		doxygen
.if !empty(PKG_OPTIONS:Mdoxygen)
PLIST.doxygen=		yes
INSTALLATION_DIRS+=	share/RE-flex/html
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen

post-configure:
	cd ${WRKSRC} && ${MAKE_PROGRAM} doc/html

post-install-doxygen:
	${INSTALL_DATA} ${WRKSRC}/doc/html/* \
		${DESTDIR}${PREFIX}/share/RE-flex/html

.else
post-install-doxygen:
	# do nothing
.endif

# copy example sources to .../share directory
PLIST_VARS+=		examples
.if !empty(PKG_OPTIONS:Mexamples)
PLIST.examples=		yes
INSTALLATION_DIRS+=	share/RE-flex/examples
DEPENDS+=		bison-[0-9]*:../../devel/bison

post-install-examples:
.for f in Make Makefile.am Makefile.in README.md
	${INSTALL_DATA} ${WRKSRC}/examples/${f}	\
		${DESTDIR}${PREFIX}/share/RE-flex/examples
.endfor
.for f in cpp json l lxx test y yaml yxx
	${INSTALL_DATA} ${WRKSRC}/examples/*\.${f} \
		${DESTDIR}${PREFIX}/share/RE-flex/examples
.endfor

.else
post-install-examples:
	# do nothing
.endif
