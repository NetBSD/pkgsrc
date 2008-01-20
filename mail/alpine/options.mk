# $NetBSD: options.mk,v 1.1 2008/01/20 15:18:55 abs Exp $
#

PKG_OPTIONS_VAR=        PKG_OPTIONS.alpine
PKG_SUPPORTED_OPTIONS=  fancythreads ldap pinepwd alpinesearchheader
PKG_SUGGESTED_OPTIONS=  pinepwd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfancythreads)
PATCH_SITES+=
http://staff.washington.edu/chappa/alpine/patches/alpine-1.00/
PATCHFILES+=            fancy.patch.gz
PATCH_DIST_STRIP=       -p1
.endif

# not tested
#.if !empty(PKG_OPTIONS:Mkerberos)
#CONFIGURE_ARGS+=       --with-krb5
#.include "../../mk/krb5.buildlink3.mk"
#.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=        --with-ldap
.include "../../databases/openldap-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpinepwd)
CONFIGURE_ARGS+= --with-passfile=.pinepwd
.endif

.if !empty(PKG_OPTIONS:Malpinesearchheader)
PATCH_SITES+=
http://staff.washington.edu/chappa/alpine/patches/alpine-1.00/
PATCHFILES+=            searchheader.patch.gz
PATCH_DIST_STRIP=       -p1
.endif
