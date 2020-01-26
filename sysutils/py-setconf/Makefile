# $NetBSD: Makefile,v 1.3 2020/01/26 17:32:11 rillig Exp $

DISTNAME=	setconf-0.7.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=xyproto/}
GITHUB_PROJECT=	setconf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://setconf.roboticoverlords.org/
COMMENT=	Small utility to change settings in configuration textfiles
LICENSE=	gnu-gpl-v2

REPLACE_PYTHON+=	setconf.py

WRKSRC=	${WRKDIR}/setconf-${PKGVERSION_NOREV}

NO_BUILD=	yes

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/setconf.py ${DESTDIR}${PREFIX}/bin/setconf
	${INSTALL_MAN} ${WRKSRC}/setconf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
