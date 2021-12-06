# $NetBSD: options.mk,v 1.1 2021/12/06 11:21:19 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pbulk
PKG_SUPPORTED_OPTIONS+=		pbulk-rsync
PKG_SUGGESTED_OPTIONS+=		pbulk-rsync

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpbulk-rsync)
DEPENDS+=	rsync-[0-9]*:../../net/rsync
.endif
