# $NetBSD: Makefile,v 1.1 2013/03/14 13:42:06 wiz Exp $

DISTNAME=	v0.3
PKGNAME=	${PYPKGPREFIX}-musicbrainz-ngs-0.3
CATEGORIES=	audio net
MASTER_SITES=	https://github.com/alastair/python-musicbrainz-ngs/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alastair/python-musicbrainz-ngs
COMMENT=	Python bindings for Musicbrainz' NGS service
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

WRKSRC=		${WRKDIR}/python-musicbrainz-ngs-0.3
DIST_SUBDIR=	py-musicbrainz-ngs

PYTHON_VERSIONS_INCLUDE_3X=	yes
EGG_NAME=			musicbrainzngs-0.3

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
