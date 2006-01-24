# $NetBSD: options.mk,v 1.2 2006/01/24 15:28:30 ben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ghostscript-esp
PKG_SUPPORTED_OPTIONS=	x11 cups
PKG_SUGGESTED_OPTIONS=	x11 cups

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
.include "../../mk/x11.buildlink3.mk"
.else
CONFIGURE_ARGS+=        --without-x
.endif

.if !empty(PKG_OPTIONS:Mcups)
CONFIGURE_ARGS+=	--enable-cups
PLIST_SUBST+=		CUPS=

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
PLIST_SUBST+=		CUPS="@comment "
.endif
