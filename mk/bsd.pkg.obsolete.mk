# $NetBSD: bsd.pkg.obsolete.mk,v 1.2 2001/11/25 19:33:45 jlam Exp $
#
# This file holds make(1) logic to allow obsolete or deprecated variables
# still to be used.  These may eventually disappear over time as the contents
# are, by definition, obsolete and deprecated.

.if defined(APACHE_SYSCONFDIR)
PKG_SYSCONFDIR.ap-ssl?=		${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.apache?=		${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.apache6?=	${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.apc-gui?=	${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.imp?=		${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.horde?=		${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.squirrelmail?=	${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.stripes?=	${APACHE_SYSCONFDIR}
.endif

.if defined(PHP_CONFDIR)
PKG_SYSCONFDIR.php?=		${PHP_CONFDIR}
.endif

.if defined(VTUN_SYSCONFDIR)
PKG_SYSCONFDIR.vtun?=		${VTUN_SYSCONFDIR}
.endif
