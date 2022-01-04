# $NetBSD: Makefile,v 1.6 2022/01/04 20:53:08 wiz Exp $

GITHUB_PROJECT=	gitinspector
DISTNAME=	gitinspector-0.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ejwa/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ejwa/gitinspector/
COMMENT=	The statistical analysis tool for git repositories
LICENSE=	gnu-gpl-v3

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/gitinspector \
		${DESTDIR}${PREFIX}/bin/gitinspector-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
