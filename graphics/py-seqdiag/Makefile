# $NetBSD: Makefile,v 1.15 2016/06/08 17:43:34 wiz Exp $

DISTNAME=	seqdiag-0.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=s/seqdiag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blockdiag.com/seqdiag/build/html/
COMMENT=	Simple sequence-diagram image generator
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-blockdiag>=1.5.0:../../graphics/py-blockdiag

PYTHON_SELF_CONFLICT=		yes

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/seqdiag.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
