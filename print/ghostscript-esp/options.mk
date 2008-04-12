# $NetBSD: options.mk,v 1.5 2008/04/12 22:43:09 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ghostscript-esp
PKG_SUPPORTED_OPTIONS=	x11 cups
PKG_SUGGESTED_OPTIONS=	x11 cups

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif

PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
CONFIGURE_ARGS+=	--enable-cups
PLIST.cups=		yes

CUPS_CONFDIR?=	${PKG_SYSCONFBASEDIR}/cups
CUPS_EGDIR=	${PREFIX}/share/examples/cups
CUPS_MODEL_DIR=	${PREFIX}/share/cups/model
CONF_FILES=	${CUPS_EGDIR}/pstoraster.convs ${CUPS_CONFDIR}/pstoraster.convs

.include "../../print/cups/buildlink3.mk"
post-install: ghostscript-esp-cups-install
ghostscript-esp-cups-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/cups/filter
	${INSTALL_SCRIPT} ${WRKSRC}/pstoraster/pstopxl			\
		${PREFIX}/libexec/cups/filter
	${INSTALL_SCRIPT} ${WRKSRC}/pstoraster/pstoraster		\
		${PREFIX}/libexec/cups/filter
	${INSTALL_DATA_DIR} ${CUPS_MODEL_DIR}
	${INSTALL_DATA} ${WRKSRC}/pstoraster/pxlcolor.ppd ${CUPS_MODEL_DIR}
	${INSTALL_DATA} ${WRKSRC}/pstoraster/pxlmono.ppd ${CUPS_MODEL_DIR}
	${INSTALL_DATA_DIR} ${CUPS_EGDIR}
	${INSTALL_DATA} ${WRKSRC}/pstoraster/pstoraster.convs ${CUPS_EGDIR}
.else
CONFIGURE_ARGS+=	--disable-cups
.endif
