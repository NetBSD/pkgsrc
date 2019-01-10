# $NetBSD: options.mk,v 1.1 2019/01/10 03:12:46 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libtai
PKG_SUPPORTED_OPTIONS+=	tai-system-clock

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtai-system-clock)
CONF_FILES+=		${EGDIR}/leapsecs.dat ${PKG_SYSCONFDIR}/leapsecs.dat
DEPENDS+=		leapsunpack-[0-9]*:../../time/leapsunpack
.endif
