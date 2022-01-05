# $NetBSD: Makefile,v 1.6 2022/01/05 15:41:22 wiz Exp $

DISTNAME=	setconf-0.7.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setconf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://setconf.roboticoverlords.org/
COMMENT=	Small utility to change settings in configuration textfiles
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/setconf.1 \
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/setconf-${PYVERSSUFFIX}.1
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} setconf setconf-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
