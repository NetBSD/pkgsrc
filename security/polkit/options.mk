# $NetBSD: options.mk,v 1.7 2023/06/22 10:41:16 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.polkit
PKG_SUPPORTED_OPTIONS=	pam
PKG_SUGGESTED_OPTIONS=	pam

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	pam

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
PLIST.pam=	yes
MAKE_DIRS+=	/etc/pam.d
CONF_FILES+=	${PREFIX}/share/examples/pam.d/polkit-1 \
		/etc/pam.d/polkit-1
INSTALLATION_DIRS+=	share/examples/pam.d
post-install: pam-move
.PHONY: pam-move
pam-move:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/pam.d/polkit-1 \
		${DESTDIR}${PREFIX}/share/examples/pam.d/polkit-1
.endif
