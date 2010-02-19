# $NetBSD: Makefile,v 1.78 2010/02/19 20:16:05 joerg Exp $

DISTNAME=	heimdal-1.1
PKGREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://www.h5l.org/dist/src/

MAINTAINER=	lha@NetBSD.org
HOMEPAGE=	http://www.h5l.org/
COMMENT=	Kerberos 5 implementation
LICENSE=	modified-bsd

CONFLICTS+=	arla-[0-9]*
CONFLICTS+=	mit-krb5-[0-9]*
CONFLICTS+=	openafs-[0-9]*
CONFLICTS+=	gss-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex
PKGCONFIG_OVERRIDE+=	tools/heimdal-gssapi.pc.in
MAKE_ENV+=		INSTALL_CATPAGES=no

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

HEIMDAL_HDB_DIR=	${VARBASE}/heimdal

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/krb5
CONFIGURE_ARGS+=	--with-hdbdir=${HEIMDAL_HDB_DIR:H:Q}
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-krb4
CONFIGURE_ARGS+=	--enable-kcm
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	${ABI:D--with-mips-abi=${ABI}}
CONFIGURE_ENV+=		COMPILE_ET=no	# build Heimdal's compile_et(1)

CFLAGS.Darwin+=		-DBIND_8_COMPAT

# Though Solaris has a <vis.h> header, it does something very unrelated
# to the BSD <vis.h> header.
#
OPSYSVARS+=		CONFIGURE_ENV
CONFIGURE_ENV.SunOS+=	ac_cv_header_vis_h=no

# Heimdal's configure script expects to find the readline.h header as
# <readline.h>.
#
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
CPPFLAGS+=		-I${BUILDLINK_PREFIX.readline}/include/readline

PLIST_VARS+=		afskauth hcrypto
.if ${OPSYS} == "IRIX"
PLIST.afskauth=		yes
.endif
.if ${MACHINE_PLATFORM:MNetBSD-[1-3]*} != ""
PLIST.hcrypto=		yes
.endif

OWN_DIRS_PERMS=		${HEIMDAL_HDB_DIR} ${REAL_ROOT_USER} ${ROOT_GROUP} 0700
SPECIAL_PERMS+=		${PREFIX}/bin/otp ${SETUID_ROOT_PERMS}
SPECIAL_PERMS=		${PREFIX}/bin/${KRB5_PREFIX}su ${SETUID_ROOT_PERMS}
RCD_SCRIPTS=		kadmind kcm kdc kpasswdd
INFO_FILES=		yes

# Dynamically determine the "replacement" headers for bits needed by
# Heimdal but are missing in the base system and add them to the PLIST.
#
GENERATE_PLIST+=	\
	( cd ${WRKSRC}/lib/roken && ${BUILD_MAKE_CMD} print-xheaders |	\
	  ${XARGS} -n 1 | ${SED} -e "s,^,include/krb5/roken/," );

.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
