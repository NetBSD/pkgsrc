# $NetBSD: Makefile,v 1.16 2022/01/01 17:32:50 wiz Exp $

DISTNAME=	hg-fastimport-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://roy.marples.name/downloads/hg-fastimport/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	https://mercurial.selenic.com/wiki/FastImportExtension
COMMENT=	Mercurial extension for importing from a git fast-import stream
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mercurial>=5.1:../../devel/py-mercurial

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
