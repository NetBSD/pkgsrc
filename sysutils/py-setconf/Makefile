# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:49 wiz Exp $

DISTNAME=	setconf-0.7.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setconf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://setconf.roboticoverlords.org/
COMMENT=	Small utility to change settings in configuration textfiles
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/setconf.1 \
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/setconf-${PYVERSSUFFIX}.1
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} setconf setconf-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
