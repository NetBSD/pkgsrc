# $NetBSD: bsd.pkg.obsolete.mk,v 1.10 2002/08/29 10:16:44 wiz Exp $
#
# This file holds make(1) logic to allow obsolete or deprecated variables
# still to be used.  These may eventually disappear over time as the contents
# are, by definition, obsolete and deprecated.

.if defined(APACHE_SUEXEC_USER)
APACHE_USER?=				${APACHE_SUEXEC_USER}
.endif

.if defined(APACHE_SYSCONFDIR)
PKG_SYSCONFDIR.ap-ssl?=			${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.apache?=			${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.apache6?=		${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.apc-gui?=		${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.cvsweb?=			${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.imp?=			${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.horde?=			${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.p5-HTTPD-User-Manage?=	${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.squirrelmail?=		${APACHE_SYSCONFDIR}
PKG_SYSCONFDIR.stripes?=		${APACHE_SYSCONFDIR}
.endif

.if defined(PHP_CONFDIR)
PKG_SYSCONFDIR.php?=			${PHP_CONFDIR}
.endif

.if defined(SSH_CONF_DIR)
PKG_SYSCONFDIR.openssh?=		${SSH_CONF_DIR}
PKG_SYSCONFDIR.ssh?=			${SSH_CONF_DIR}
.endif

.if defined(VTUN_SYSCONFDIR)
PKG_SYSCONFDIR.vtun?=			${VTUN_SYSCONFDIR}
.endif

.if defined(POSTFIX_USE_SASL_AUTH)
USE_SASL=				YES
.endif

.if defined(SAMBA_WITH_CUPS)
USE_CUPS=				YES
.endif

.if defined(SQUID_SYSCONFDIR)
PKG_SYSCONFDIR.squid?=			${SQUID_SYSCONFDIR}
.endif

