# $NetBSD: options.mk,v 1.1 2004/11/25 19:25:28 xtraeme Exp $
#
# XXX Support for the following variables will be removed after the
# XXX pkgsrc-2004Q4 branch is released:
# XXX
# XXX USE_KERBEROS
# XXX USE_PÂM

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:MLinux)
.  if defined(USE_PAM) && !empty(USE_PAM:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	PAM
.  endif
.endif

.if defined(USE_KERBEROS) && !empty(USE_KERBEROS:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	kerberos
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.openssh
PKG_SUPPORTED_OPTIONS=	kerberos hpn-patch

.if !empty(OPSYS:MLinux)
PKG_SUPPORTED_OPTIONS+= PAM
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=        --with-kerberos5=${KRB5BASE}
.endif

.if !empty(PKG_OPTIONS:Mhpn-patch)
PATCHFILES=		openssh-3.9p1-hpn.diff
PATCH_SITES=		http://www.psc.edu/networking/projects/hpn-ssh/
PATCH_DIST_STRIP=	-p1
.endif

.if !empty(PKG_OPTIONS:MPAM)
# XXX: PAM authentication causes memory faults, and haven't tracked down
# XXX: why yet.  For the moment, disable PAM authentication for non-Linux.
.include "../../security/PAM/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
PLIST_SRC+=		${.CURDIR}/PLIST.pam
MESSAGE_SRC+=		${.CURDIR}/MESSAGE.pam
.endif
