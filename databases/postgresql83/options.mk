# $NetBSD: options.mk,v 1.1.1.1 2008/03/04 12:41:36 adam Exp $

PKG_SUPPORTED_OPTIONS+=		# empty

.include "../../mk/bsd.options.mk"

###
### PAM authentication for the PostgreSQL backend.
###
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif
