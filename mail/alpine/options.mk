# $NetBSD: options.mk,v 1.4 2012/10/10 19:45:49 markd Exp $
#

PKG_OPTIONS_VAR=        PKG_OPTIONS.alpine
PKG_SUPPORTED_OPTIONS=  fancythreads ldap kerberos maildir pinepwd alpinesearchheader
PKG_SUGGESTED_OPTIONS=  pinepwd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfancythreads)
PATCH_SITES+=http://staff.washington.edu/chappa/alpine/patches/${DISTNAME}/
PATCHFILES+=            fancy.patch.gz
PATCH_DIST_STRIP=       -p1
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
CONFIGURE_ARGS+=	--with-krb5
.include "../../mk/krb5.buildlink3.mk"
MAKE_ENV+=	KRB5_TYPE=${KRB5_TYPE}
MAKE_FLAGS+=	EXTRAAUTHENTICATORS=gss
EXTRASPECIALS+=	GSSDIR=${KRB5BASE}
CFLAGS.heimdal=	-DHEIMDAL_KRB5
CFLAGS+=	${CFLAGS.${KRB5_TYPE}}
MAKE_FLAGS+=	EXTRALDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	EXTRACFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	EXTRASPECIALS=${EXTRASPECIALS:Q}
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=        --with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
.include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if !empty(PKG_OPTIONS:Mmaildir)
PATCH_SITES+=http://staff.washington.edu/chappa/alpine/patches/${DISTNAME}/
PATCHFILES+=            maildir.patch.gz
PATCH_DIST_STRIP=       -p1
.endif

.if !empty(PKG_OPTIONS:Mpinepwd)
CONFIGURE_ARGS+= --with-passfile=.pinepwd
.endif

.if !empty(PKG_OPTIONS:Malpinesearchheader)
PATCH_SITES+=http://staff.washington.edu/chappa/alpine/patches/${DISTNAME}/
PATCHFILES+=            searchheader.patch.gz
PATCH_DIST_STRIP=       -p1
.endif
