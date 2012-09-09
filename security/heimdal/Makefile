# $NetBSD: Makefile,v 1.92 2012/09/09 09:23:06 cheusov Exp $

DISTNAME=	heimdal-1.5.2
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.h5l.org/dist/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.h5l.org/
COMMENT=	Kerberos 5 implementation
LICENSE=	modified-bsd

CONFLICTS+=	arla-[0-9]*
CONFLICTS+=	mit-krb5-[0-9]*
CONFLICTS+=	openafs-[0-9]*
CONFLICTS+=	gss-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*

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
CONFIGURE_ARGS+=	--enable-kcm
CONFIGURE_ARGS+=	--enable-pthread-support
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/krb5
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-hdbdir=${HEIMDAL_HDB_DIR}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	${ABI:D--with-mips-abi=${ABI}}
CONFIGURE_ENV+=		COMPILE_ET=no	# build Heimdal's compile_et(1)
# XXX Grand Central Dispatch is broken in 1.4
CONFIGURE_ENV+=		ac_cv_funclib_dispatch_async_f=no

CFLAGS.Darwin+=		-DBIND_8_COMPAT

# Though Solaris has a <vis.h> header, it does something very unrelated
# to the BSD <vis.h> header.
OPSYSVARS+=		CONFIGURE_ENV
CONFIGURE_ENV.SunOS+=	ac_cv_header_vis_h=no

# Heimdal's configure script expects to find the readline.h header as
# <readline.h>.
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
CPPFLAGS+=		-I${BUILDLINK_PREFIX.readline}/include/readline

PLIST_VARS+=		afskauth hcrypto
.if ${OPSYS} == "IRIX"
PLIST.afskauth=		yes
.endif

.include "../../security/openssl/builtin.mk"

.if ${MACHINE_PLATFORM:MNetBSD-[1-3]*} != "" || \
    (${OPSYS} == "SunOS" && !empty(USE_BUILTIN.openssl:Myes))
PLIST.hcrypto=		yes
.endif

OWN_DIRS_PERMS=		${HEIMDAL_HDB_DIR} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
SPECIAL_PERMS+=		${PREFIX}/bin/otp ${SETUID_ROOT_PERMS}
SPECIAL_PERMS=		${PREFIX}/bin/${KRB5_PREFIX}su ${SETUID_ROOT_PERMS}
RCD_SCRIPTS=		kadmind kcm kdc kpasswdd
INFO_FILES=		yes

# Dynamically determine the "replacement" headers for bits needed by
# Heimdal but are missing in the base system and add them to the PLIST.
GENERATE_PLIST+=	\
	( cd ${WRKSRC}/lib/roken && ${BUILD_MAKE_CMD} print-xheaders |	\
	  ${XARGS} -n 1 | ${SED} -e "s,^,include/krb5/roken/," );

TEST_TARGET=		check

# remove manpages conficting with OpenSSL keeping only the important ones
pre-configure:
	cd ${WRKSRC}/doc/doxyout/hcrypto && \
	${GREP} -e /hcrypto_ -e /page_ manpages > manpages.new && \
	mv manpages.new manpages

# Avoid 'cat: cannot open ./localefiles: No such file or directory'
pre-build:
	${TOUCH} ${WRKSRC}/po/localefiles

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
