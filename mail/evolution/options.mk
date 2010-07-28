# $NetBSD: options.mk,v 1.4 2010/07/28 07:44:50 dsainty Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.evolution
PKG_SUPPORTED_OPTIONS=	krb5 ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl) && !empty(PKG_OPTIONS:Mkrb5)
# If Kerberos is enabled, the libcrypto library is linked in, which causes
# function name conflicts with libsoftokn3 provided by Mozilla NSS.  These
# cause runtime crashes, so don't allow these options to be specified
# together.
PKG_FAIL_REASON+=	"Kerberos support conflicts with SSL"
.endif

.if !empty(PKG_OPTIONS:Mkrb5)
CPPFLAGS+=		-I/usr/include/gssapi
CPPFLAGS+=		-I/usr/include/krb5
CONFIGURE_ARGS+=	--with-krb5=/usr
.  include "../../mk/krb5.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-krb5
.endif

PLIST_VARS+=		smime
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-nss=yes
PLIST.smime=		yes
PRINT_PLIST_AWK+=	/smime/ { print "$${HAVE_SMIME}" $$0; next; }
# XXX Workaround for the following problem: addressbook/util/libeabutil.la
# is compiled as a static library only which uses the NSS stuff.  When other
# parts of the program use this .la archive, they get the right -L flags
# (from the dependency_libs variable) but not the rpaths.  buildlink3 should
# add rpath flags to the dependency_libs, but there is an strange comment
# in the wrapper saying that it shouldn't.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.nss}/lib/nss
BUILDLINK_API_DEPENDS.nss+=		nss>=3.9.2nb3
.  include "../../devel/nspr/buildlink3.mk"
.  include "../../devel/nss/buildlink3.mk"

CPPFLAGS+=		-I${BUILDLINK_PREFIX.nss}/include/nss/nss

post-wrapper:
	cd ${BUILDLINK_DIR}/lib/pkgconfig && ${LN} -s nspr.pc mozilla-nspr.pc
	cd ${BUILDLINK_DIR}/lib/pkgconfig && ${LN} -s nss.pc mozilla-nss.pc
.else
CONFIGURE_ARGS+=	--disable-nss
.endif
