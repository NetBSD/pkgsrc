# $NetBSD: options.mk,v 1.6 2009/03/08 15:54:26 tron Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.milter-greylist
PKG_OPTIONS_REQUIRED_GROUPS=	mta
PKG_OPTIONS_GROUP.mta=		postfix-milter sendmail-milter
PKG_SUPPORTED_OPTIONS=		dnsrbl drac spf
PKG_SUGGESTED_OPTIONS=		dnsrbl sendmail-milter spf

.include "../../mk/bsd.options.mk"

###
### DNS Realtime Black List
###
.if !empty(PKG_OPTIONS:Mdnsrbl)
CONFIGURE_ARGS+=	--enable-dnsrbl --with-thread-safe-resolver
.endif

###
### Dynamic Relay Authorization Control
###
.if empty(PKG_OPTIONS:Mdrac)
CONFIGURE_ARGS+=	--disable-drac
.else
DRACD_DB?=		/etc/mail/dracd.db

CONFIGURE_ARGS+=	--enable-drac --with-drac-db=${DRACD_DB}
.endif

###
### Postfix support
###
.if !empty(PKG_OPTIONS:Mpostfix-milter)
CONFIGURE_ARGS+=	--enable-postfix

POSTFIX_QUEUE_DIR?=	${VARBASE}/spool/postfix
BUILD_DEFS+=		VARBASE

PKG_GROUPS?=		postfix
PKG_USERS?=		postfix:postfix
PKG_GECOS.postfix=	Postfix User
PKG_HOME.postfix=	${POSTFIX_QUEUE_DIR}

MILTER_USER=		postfix
.endif

###
### Sendmail support
###
.if !empty(PKG_OPTIONS:Msendmail-milter)
PKG_GROUPS=		smmsp
PKG_USERS=		smmsp:smmsp
PKG_GECOS.smmsp=	Sendmail Message Submission Program

MILTER_USER=		smmsp
.endif

###
### Sender Policy Framework
###
.if empty(PKG_OPTIONS:Mspf)
CONFIGURE_ARGS+=	--disable-libspf2
.else
.include "../../mail/libspf2/buildlink3.mk"

CONFIGURE_ARGS+=	--with-libspf2=${PREFIX:Q}
.endif
