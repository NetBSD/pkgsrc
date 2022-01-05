# $NetBSD: Makefile,v 1.3 2022/01/05 20:47:35 wiz Exp $

GITHUB_PROJECT=	gitinspector
DISTNAME=	gitinspector-0.5.0.dev0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ejwa/}
GITHUB_TAG=	6d77989e341e043c9a7f09757000d75701b32d84

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ejwa/gitinspector/
COMMENT=	The statistical analysis tool for git repositories
LICENSE=	gnu-gpl-v3

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_PKG_RESOURCES=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/gitinspector \
		${DESTDIR}${PREFIX}/bin/gitinspector${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
