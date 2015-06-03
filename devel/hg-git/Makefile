# $NetBSD: Makefile,v 1.19 2015/06/03 12:53:56 taca Exp $

DISTNAME=	hg-git-0.8.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://hg-git.github.com/
COMMENT=	Git plugin for Mercurial
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.8.6:../../devel/py-dulwich
DEPENDS+=	mercurial>=1.9.4:../../devel/mercurial

WRKSRC=		${WRKDIR}/durin42-hg-git-e6489cf3fe8c
USE_LANGUAGES=	#none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-dulwich

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
