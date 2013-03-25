# $NetBSD: Makefile,v 1.35 2013/03/25 10:09:04 sbd Exp $
#

DISTNAME=		pkgin-0.6.3.1.1
CATEGORIES=		pkgtools
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/imil/

MAINTAINER=		imil@NetBSD.org
HOMEPAGE=		http://pkgin.net/
COMMENT=		Apt / yum like tool for managing pkgsrc binary packages
LICENSE=		modified-bsd

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/repositories.conf.example		\
			${PKG_SYSCONFDIR}/${PKGBASE}/repositories.conf

OWN_DIRS+=		${PKG_SYSCONFDIR}/${PKGBASE}
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${EGDIR}

WRKSRC=			${WRKDIR}/pkgin

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Adjusting path.
SUBST_FILES.path=	Makefile.in actions.c pkgin.1
SUBST_SED.path=		-e "s|/usr/pkg/etc|${PKG_SYSCONFDIR}|g"
SUBST_SED.path+=	-e "s|/usr/sbin|${PKG_TOOLS_BIN}|g"
SUBST_SED.path+=	-e "s|/var|${VARBASE}|g"
SUBST_SED.path+=	-e "s|/usr/pkg|${PREFIX}|g"
SUBST_SED.path+=	-e "s|!=.*uname -p|=	${MACHINE_ARCH}|g"

GNU_CONFIGURE=		yes
USE_FEATURES=		nbcompat
USE_TOOLS+=		nroff

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		osrel
SUBST_STAGE.osrel=	pre-configure
SUBST_MESSAGE.osrel=	Adjusting repository OS release
SUBST_FILES.osrel=	REPOSITORIES
SUBST_SED.osrel=	-e "s|@OSREL@|${OS_VERSION:C/_.*//}|"
.endif

MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

DEPENDS+=		pkg_install>=20110215:../../pkgtools/pkg_install

# those have official repositories
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "Minix"
pre-install:
	${GREP} -i ${OPSYS} ${WRKSRC}/REPOSITORIES >> 		\
		${WRKSRC}/repositories.conf
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgin ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pkgin.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/repositories.conf			\
		${DESTDIR}${EGDIR}/repositories.conf.example

# libfetch has no builtin.mk and is included in NetBSD>=5
.if ${OPSYS} != "NetBSD" || \
	(${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[0-4].*))
.	include "../../net/libfetch/buildlink3.mk"
.endif

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
