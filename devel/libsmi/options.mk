# $NetBSD: options.mk,v 1.1 2022/01/08 14:50:59 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libsmi
PKG_SUPPORTED_OPTIONS=		wget

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	smicache
.if !empty(PKG_OPTIONS:Mwget)
DEPENDS+=	wget-[0-9]*:../../net/wget
PLIST.smicache=	yes
.else
post-install: remove-smicache
.PHONY: remove-smicache
remove-smicache:
	rm ${DESTDIR}${PREFIX}/bin/smicache
.endif
