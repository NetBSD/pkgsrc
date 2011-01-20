# $NetBSD: Makefile,v 1.8 2011/01/20 18:14:09 imil Exp $
#

DISTNAME=		pkgin-0.3.3.4
CATEGORIES=		pkgtools
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/imil/

MAINTAINER=		imil@gcu.info
HOMEPAGE=		http://imil.net/pkgin/
COMMENT=		Apt / yum like tool for managing pkgsrc binary packages
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

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
SUBST_SED.path+=	-e "s|/usr/pkg|${PREFIX}|g"
SUBST_SED.path+=	-e "s|/usr/sbin|${PKG_TOOLS_BIN}|g"
SUBST_SED.path+=	-e "s|/var|${VARBASE}|g"

GNU_CONFIGURE=		yes
USE_FEATURES=		nbcompat

NBCOMPAT_CONFIGURE_ARGS+=	--enable-db

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgin ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pkgin.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/repositories.conf			\
		${DESTDIR}${EGDIR}/repositories.conf.example


.include "../../mk/bsd.prefs.mk"

# libfetch has no builtin.mk and is included in NetBSD>=5
.if ${OPSYS} != "NetBSD" || \
	(${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[0-4].*))
.	include "../../net/libfetch/buildlink3.mk"
.endif

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
