# $NetBSD: bsd.pkg.obsolete.mk,v 1.14 2004/07/21 16:19:26 jlam Exp $
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

.if defined(SAMBA_WITH_CUPS)
USE_CUPS=				YES
.endif

.if defined(SQUID_SYSCONFDIR)
PKG_SYSCONFDIR.squid?=			${SQUID_SYSCONFDIR}
.endif

.if defined(ELK_USE_X11)
ELK_GUI=	xaw
.endif

.if defined(PRIV_CONF_DIR)
PKG_SYSCONFDIR.priv?=	${PRIV_CONF_DIR}
.endif

##
## The following Postfix-related section will be removed after the
## pkgsrc-2004Q3 branch is released.
##
.if defined(POSTFIX_USE_INET6) || defined(POSTFIX_USE_TLS) || \
    defined(POSTFIX_USE_PCRE) || defined(POSTFIX_USE_MYSQL) || \
    defined(POSTFIX_USE_PGSQL) || defined(POSTFIX_USE_VERP) || \
    defined(POSTFIX_USE_SASL_AUTH) || defined(USE_SASL) || \
    defined(USE_SASL2) || defined(USE_OPENLDAP)
.  if !defined(POSTFIX_OPTIONS)
.    if defined(POSTFIX_USE_INET6) && !empty(POSTFIX_USE_INET6:M[yY][eE][sS])
POSTFIX_OPTIONS+=	inet6
.    endif
.    if defined(POSTFIX_USE_TLS) && !empty(POSTFIX_USE_TLS:M[yY][eE][sS])
POSTFIX_OPTIONS+=	tls
.    endif
.    if defined(POSTFIX_USE_PCRE) && !empty(POSTFIX_USE_PCRE:M[yY][eE][sS])
POSTFIX_OPTIONS+=	pcre 
.    endif
.    if defined(POSTFIX_USE_MYSQL) && !empty(POSTFIX_USE_MYSQL:M[yY][eE][sS])
POSTFIX_OPTIONS+=	mysql
.    endif
.    if defined(POSTFIX_USE_PGSQL) && !empty(POSTFIX_USE_PGSQL:M[yY][eE][sS])
POSTFIX_OPTIONS+=	pgsql
.    endif
.    if defined(POSTFIX_USE_VERP) && !empty(POSTFIX_USE_VERP:M[yY][eE][sS])
POSTFIX_OPTIONS+=	verp
.    endif
.    if defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[yY][eE][sS])
POSTFIX_OPTIONS+=	ldap
.    endif
.    if defined(POSTFIX_USE_SASL_AUTH) && defined(POSTFIX_USE_SASL_AUTH)
USE_SASL=		YES
.    endif
.    if defined(USE_SASL) && !empty(USE_SASL:M[yY][eE][sS])
POSTFIX_OPTIONS+=	sasl
.    endif
.    if defined(USE_SASL2) && !empty(USE_SASL2:M[yY][eE][sS])
POSTFIX_OPTIONS+=	sasl
.    endif
.  endif
.endif
