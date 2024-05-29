# $NetBSD: Makefile,v 1.5 2024/05/29 16:33:23 adam Exp $

DISTNAME=		opensmtpd-extras-6.7.1_20240228
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=OpenSMTPD/}
GITHUB_PROJECT=		OpenSMTPD-extras
#GITHUB_RELEASE=	${PKGVERSION_NOREV}
GITHUB_TAG=		86f2f1927743257674d29d4fed250bdce5d1c0b5

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/OpenSMTPD/OpenSMTPD-extras/
COMMENT=	Addons for OpenSMTPD
LICENSE=	isc

BUILD_DEFS+=		VARBASE
PTHREAD_AUTO_VARS=	yes

CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE   # strtonum()

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	awk mandoc pkg-config
USE_TOOLS+=	automake aclocal autoheader autoconf

DEPENDS+=	opensmtpd-[0-9]*:../../mail/opensmtpd

PKG_SYSCONFSUBDIR=	smtpd

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_FILES.paths=	configure.ac extras/tables/table-mysql/table-mysql.5 \
			extras/tables/table-postgres/table-postgres.5 \
			extras/tables/table-sqlite/table-sqlite.5
SUBST_SED.paths+=	-e "s:/usr/local/bin:${PREFIX}/bin:g"
SUBST_SED.paths+=	-e "s:/usr/local/lib:${PREFIX}/lib:g"
SUBST_SED.paths+=	-e "s:/usr/local/include:${PREFIX}/include:g"
SUBST_SED.paths+=	-e "s:/usr/local/ssl:${SSLBASE}:g"
SUBST_SED.paths+=	-e "s:/etc/openssl:${SSLDIR}:g"
SUBST_SED.paths+=	-e "s:/usr/local:${PREFIX}:g"
SUBST_SED.paths+=	-e "s:/etc/mail:${PKG_SYSCONFDIR}:g"
SUBST_SED.paths+=	-e "s:/var/vmail:${VARBASE}/vmail:g"

.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		ints
SUBST_MESSAGE.ints=	SunOS stdint(3) doesn't provide `u_int*' typedefs
SUBST_STAGE.ints=	pre-configure
SUBST_FILES.ints+=	extras/tables/table-ldap/*.c
SUBST_FILES.ints+=	extras/tables/table-ldap/*.h
SUBST_SED.ints=		-e 's|u_int|uint|g'
.endif

CONFIGURE_ENV+=		TEST_MINUS_S_SH=${SH:Q}
CONFIGURE_ARGS+=	--with-pie
CONFIGURE_ARGS+=	--with-mantype=man
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-user-smtpd=_smtpd
CONFIGURE_ARGS+=	--with-path-empty=${VARBASE}/empty
CONFIGURE_ARGS+=	--with-libssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}

CONFIGURE_ARGS+=	--with-filter-stub	\
			--with-filter-trace	\
			--with-filter-void	\
			--with-queue-null	\
			--with-queue-ram	\
			--with-queue-stub	\
			--with-scheduler-ram	\
			--with-scheduler-stub	\
			--with-table-passwd	\
			--with-table-socketmap	\
			--with-table-stub	\
			--with-tool-stats

.include "options.mk"

INSTALL_TARGET=		install-strip
INSTALLATION_DIRS+=	libexec/opensmtpd share/examples/opensmtpd

pre-configure:
	cd ${WRKSRC} && ${PREFIX}/bin/libtoolize --copy --force
	cd ${WRKSRC} && ${TOOLS_CMD.aclocal}
	cd ${WRKSRC} && ${TOOLS_CMD.autoconf}
	cd ${WRKSRC} && ${TOOLS_CMD.autoheader}
	cd ${WRKSRC} && ${TOOLS_CMD.automake} --foreign --add-missing --copy

post-install:
.for f in table-ldap.conf.example
	${INSTALL_DATA} ${WRKSRC}/extras/tables/table-ldap/${f}	\
		${DESTDIR}${PREFIX}/share/examples/opensmtpd/${f:S/.example//}
.endfor

.include "../../security/libretls/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
