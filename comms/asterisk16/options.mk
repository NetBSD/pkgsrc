# $NetBSD: options.mk,v 1.4 2010/03/01 07:06:48 jnemeth Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.asterisk
PKG_SUPPORTED_OPTIONS=		zaptel x11 unixodbc ilbc
PKG_OPTIONS_LEGACY_OPTS+=	gtk:x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		zaptel x11 unixodbc ilbc

# Asterisk now uses DAHDI, not zaptel; not implemented yet...
#.if !empty(PKG_OPTIONS:Mzaptel)
## zaptel only supported under NetBSD at the moment
#.  include "../../comms/zaptel-netbsd/buildlink3.mk"
#PLIST.zaptel=		yes
#.else
#MAKE_FLAGS+=		WITHOUT_ZAPTEL=1
#.endif

# gtkconsole depends on GTK 1.x
.if !empty(PKG_OPTIONS:Mx11)
.  include "../../x11/gtk/buildlink3.mk"
.  include "../../devel/SDL/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sdl
CONFIGURE_ARGS+=	--with-gtk
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--without-sdl
CONFIGURE_ARGS+=	--without-gtk
.endif

.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
.  include "../../devel/libltdl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ltdl
CONFIGURE_ARGS+=	--with-odbc
PLIST.unixodbc=		yes
.else
CONFIGURE_ARGS+=	--without-ltdl
CONFIGURE_ARGS+=	--without-odbc
.endif

.if !empty(PKG_OPTIONS:Milbc)
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		rfc3951.txt
SITES.rfc3951.txt=	http://www.ietf.org/rfc/
DISTFILES+=		extract-cfile.awk
SITES.extract-cfile.awk=	http://www.ilbcfreeware.org/documentation/
USE_TOOLS+=		awk
PLIST.ilbc=		yes
.endif

.if !empty(PKG_OPTIONS:Mx11) || !empty(PKG_OPTIONS:Munixodbc) || !empty(PKG_OPTIONS:Milbc)
RUN_MENUSELECT= # empty
MAKE_FLAGS+=	GLOBAL_MAKEOPTS=${WRKSRC}/pkgsrc.makeopts
.endif
post-configure:
.if !empty(PKG_OPTIONS:Mx11)
	${ECHO} "MENUSELECT_PBX=-pbx_gtkconsole" >> ${WRKSRC}/pkgsrc.makeopts
.endif
.if !empty(PKG_OPTIONS:Munixodbc)
	${ECHO} "MENUSELECT_OPTS_app_voicemail=ODBC_STORAGE" >> ${WRKSRC}/pkgsrc.makeopts
.endif
.if !empty(PKG_OPTIONS:Milbc)
	${ECHO} "MENUSELECT_CODECS=-codec_ilbc" >> ${WRKSRC}/pkgsrc.makeopts
.endif
.if defined(RUN_MENUSELECT)
	# this is a hack to work around a bug in menuselect
	cd ${WRKSRC} && make menuselect.makeopts
.endif

post-extract:
.if !empty(PKG_OPTIONS:Milbc)
	cp ${DISTDIR}/${DIST_SUBDIR}/rfc3951.txt ${WRKSRC}/codecs/ilbc
	cp ${DISTDIR}/${DIST_SUBDIR}/extract-cfile.awk ${WRKSRC}/codecs/ilbc
	cd ${WRKSRC}/codecs/ilbc && ${AWK} -f extract-cfile.awk < rfc3951.txt
.endif
