# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:08 wiz Exp $

GITHUB_PROJECT=	gitinspector
DISTNAME=	gitinspector-0.5.0.dev0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ejwa/}
GITHUB_TAG=	6d77989e341e043c9a7f09757000d75701b32d84

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ejwa/gitinspector/
COMMENT=	The statistical analysis tool for git repositories
LICENSE=	gnu-gpl-v3

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/gitinspector \
		${DESTDIR}${PREFIX}/bin/gitinspector${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
