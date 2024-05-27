# $NetBSD: Makefile,v 1.130 2024/05/27 23:27:10 riastradh Exp $

DISTNAME=		pkgin-23.8.1
PKGREVISION=		4
CATEGORIES=		pkgtools
MASTER_SITES=		${MASTER_SITE_GITHUB:=NetBSDfr/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		jperkin@pkgsrc.org
HOMEPAGE=		http://pkgin.net/
COMMENT=		Apt / yum like tool for managing pkgsrc binary packages
LICENSE=		modified-bsd

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/repositories.conf.example		\
			${PKG_SYSCONFDIR}/${PKGBASE}/repositories.conf

OWN_DIRS+=		${PKG_SYSCONFDIR}/${PKGBASE}
OWN_DIRS+=		${VARBASE}/db/pkgin

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${EGDIR}

BUILD_DEFS+=		PKGIN_REPOSITORY_URL
BUILD_DEFS+=		VARBASE

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-maintainer-mode
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-dbdir=${VARBASE}/db/pkgin
CONFIGURE_ARGS+=	--with-machine-arch=${MACHINE_ARCH}
CONFIGURE_ARGS+=	--with-pkg-install=${PKG_TOOLS_BIN}
CONFIGURE_ARGS+=	--with-libarchive=${BUILDLINK_PREFIX.libarchive}
CONFIGURE_ARGS+=	--with-libfetch=${BUILDLINK_PREFIX.libfetch}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}

USE_FEATURES=		nbcompat

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES.NetBSD+=	osrel
SUBST_STAGE.osrel=	pre-configure
SUBST_MESSAGE.osrel=	Adjusting repository OS release
SUBST_FILES.osrel=	REPOSITORIES
SUBST_SED.osrel=	-e "s|@OSREL@|${OS_VERSION:C/_.*//}|"

CFLAGS.SunOS+=		-D_FILE_OFFSET_BITS=64

DEPENDS+=		pkg_install>=20200701:../../pkgtools/pkg_install

.include "options.mk"

USE_TOOLS+=	autoconf automake

pre-configure:
	@${STEP_MSG} Regenerating configure
	${RUN}cd ${WRKSRC} && autoreconf -fiv

# those have official repositories
.if !empty(PKGIN_REPOSITORY_URL)
pre-install:
	${ECHO} ${PKGIN_REPOSITORY_URL} >> ${WRKSRC}/repositories.conf
.elif ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "Minix"
pre-install:
	${GREP} -i ${OPSYS} ${WRKSRC}/REPOSITORIES >> 			\
		${WRKSRC}/repositories.conf
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/repositories.conf			\
		${DESTDIR}${EGDIR}/repositories.conf.example
	${INSTALL_DATA} ${WRKSRC}/preferred.conf			\
		${DESTDIR}${EGDIR}/preferred.conf.example

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../net/libfetch/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
