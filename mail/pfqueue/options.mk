# $NetBSD: options.mk,v 1.3 2019/05/23 19:23:07 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pfqueue

PKG_SUPPORTED_OPTIONS=	exim postfix socket
PKG_SUGGESTED_OPTIONS=	postfix socket

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	exim postfix socket

###
### Enable Exim support
###
.if !empty(PKG_OPTIONS:Mexim)
PFQ_BACKENDS+=	libpfq_exim.la
PLIST.exim=	yes
.endif

###
### Enable Postfix support
###
.if !empty(PKG_OPTIONS:Mpostfix)
PFQ_BACKENDS+=	libpfq_postfix2.la
PLIST.postfix=	yes
.endif

###
### Enable socket support
###
.if !empty(PKG_OPTIONS:Msocket)
PFQ_BACKENDS+=	libpfq_socket.la
PLIST.socket=	yes
.endif

SUBST_CLASSES+=		backends
SUBST_STAGE.backends=	pre-configure
SUBST_MESSAGE.backends=	Enabling backends
SUBST_FILES.backends=	backends/Makefile.in
SUBST_VARS.backends=	PFQ_BACKENDS
