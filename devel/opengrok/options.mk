# $NetBSD: options.mk,v 1.3 2013/12/31 22:56:12 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opengrok

PKG_SUPPORTED_OPTIONS=	svn

.include "../../mk/bsd.options.mk"

###
### Support Subversion revision control
###
.if !empty(PKG_OPTIONS:Msvn)
.  include "../../devel/subversion-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.subversion-base+= subversion-base>=1.3.0
.endif
