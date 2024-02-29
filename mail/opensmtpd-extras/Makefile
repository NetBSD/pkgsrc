# $NetBSD: Makefile,v 1.1 2024/02/29 20:57:37 vins Exp $

DISTNAME=	opensmtpd-extras-6.7.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenSMTPD/}
GITHUB_PROJECT=	OpenSMTPD-extras
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/OpenSMTPD/OpenSMTPD-extras/
COMMENT=	Addons for OpenSMTPD
LICENSE=	isc

BUILD_DEFS+=		VARBASE
PTHREAD_AUTO_VARS=	yes

CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE   # strtonum()

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	awk mandoc pkg-config sh
USE_TOOLS+=	automake aclocal autoheader autoconf

DEPENDS+=	opensmtpd-[0-9]*:../../mail/opensmtpd

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_FILES.paths=	configure.ac
SUBST_SED.paths+=	-e "s:/usr/local/bin:${PREFIX}/bin:g"
SUBST_SED.paths+=	-e "s:/usr/local/lib:${PREFIX}/lib:g"
SUBST_SED.paths+=	-e "s:/usr/local/include:${PREFIX}/include:g"
SUBST_SED.paths+=	-e "s:/usr/local/ssl:${SSLDIR}:g"

CONFIGURE_ENV+=		TEST_MINUS_S_SH=${SH:Q}
CONFIGURE_ARGS+=	--with-pie
CONFIGURE_ARGS+=	--with-mantype=man
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/smtpd
CONFIGURE_ARGS+=	--with-user-smtpd=_smtpd
CONFIGURE_ARGS+=	--with-path-empty=${VARBASE}/empty
CONFIGURE_ARGS+=	--with-libssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}

CONFIGURE_ARGS+=	--with-cflags=${CFLAGS:Q}	\
			--with-cppflags=${CPPFLAGS:Q}	\
			--with-ldflags=${LDFLAGS:Q}

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
INSTALLATION_DIRS+=	libexec/opensmtpd

pre-configure:
	cd ${WRKSRC} && ${PREFIX}/bin/libtoolize --copy --force
	cd ${WRKSRC} && ${TOOLS_CMD.aclocal}
	cd ${WRKSRC} && ${TOOLS_CMD.autoconf}
	cd ${WRKSRC} && ${TOOLS_CMD.autoheader}
	cd ${WRKSRC} && ${TOOLS_CMD.automake} --foreign --add-missing --copy

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
