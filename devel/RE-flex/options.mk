# $NetBSD: options.mk,v 1.4 2024/03/21 20:44:40 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.RE-flex
PKG_SUPPORTED_OPTIONS=	cpu-optimization doxygen examples
PKG_SUGGESTED_OPTIONS=	examples

.include "../../mk/bsd.options.mk"

# don't build with cpu optimizations detected during configure
.if empty(PKG_OPTIONS:Mcpu-optimization)
CONFIGURE_ARGS+=	--disable-avx
CONFIGURE_ARGS+=	--disable-sse2
CONFIGURE_ARGS+=	--disable-neon
.endif

# build and install html docs
PLIST_VARS+=		doxygen
.if !empty(PKG_OPTIONS:Mdoxygen)
PLIST.doxygen=		yes
DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}/html

TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen

post-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} doc/html

.PHONY: post-install-doxygen

post-install-doxygen:
	${INSTALL_DATA} ${WRKSRC}/doc/html/* \
		${DESTDIR}${PREFIX}/${DOCDIR}/html

.else
post-install-doxygen:
	# do nothing
.endif

# install example sources
PLIST_VARS+=		examples
.if !empty(PKG_OPTIONS:Mexamples)
PLIST.examples=		yes
EXAMPLEDIR=		share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${EXAMPLEDIR}

DEPENDS+=		bison-[0-9]*:../../devel/bison

SUBST_CLASSES+=		path
SUBST_FILES.path=	examples/Make
SUBST_MESSAGE.path=	Updating paths.
SUBST_STAGE.path=	pre-install
SUBST_VARS.path=	CC CXX PREFIX

.PHONY: post-install-examples

post-install-examples:
	${INSTALL_DATA} ${WRKSRC}/examples/Make \
		${DESTDIR}${PREFIX}/${EXAMPLEDIR}/Makefile
.  for f in c cpp json hpp l lisp lua lxx md test txt y yaml yxx
	${INSTALL_DATA} ${WRKSRC}/examples/*\.${f} \
		${DESTDIR}${PREFIX}/${EXAMPLEDIR}
.  endfor

.else
post-install-examples:
	# do nothing
.endif
