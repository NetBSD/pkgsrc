# $NetBSD: options.mk,v 1.1 2009/11/20 13:14:13 fhajny Exp $

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
SUBST_STAGE.backends=	post-patch
SUBST_MESSAGE.backends=	Enabling backends
SUBST_FILES.backends=	backends/Makefile.in
SUBST_SED.backends=	-e 's|@PFQ_BACKENDS@|${PFQ_BACKENDS:Q}|'
