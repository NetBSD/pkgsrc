# $NetBSD: Makefile,v 1.1 2026/06/06 18:39:55 wiz Exp $

DISTNAME=	tuptime-5.2.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=rfmoz/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rfmoz/tuptime/
COMMENT=	System uptime history tracker
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

NO_BUILD=	yes

REPLACE_PYTHON=	src/tuptime

RCD_SCRIPTS=	tuptime

PKG_GROUPS=		_tuptime
PKG_USERS=		_tuptime:_tuptime
PKG_GECOS._tuptime=	Tuptime user
PKG_HOME._tuptime=	${VARBASE}/lib/tuptime

BUILD_DEFS+=		VARBASE
OWN_DIRS_PERMS+=	${VARBASE}/lib/tuptime _tuptime _tuptime 0755

DOCDIR=		${PREFIX}/share/doc/tuptime

INSTALLATION_DIRS+=	bin ${DOCDIR} ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/tuptime ${DESTDIR}${PREFIX}/bin/tuptime
	${INSTALL_MAN} ${WRKSRC}/src/man/tuptime.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tuptime.1
	${INSTALL_DATA} ${WRKSRC}/tuptime-manual.txt ${DESTDIR}${DOCDIR}/tuptime-manual.txt
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc ${DESTDIR}${DOCDIR}/README.pkgsrc

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
