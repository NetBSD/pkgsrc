# $NetBSD: Makefile,v 1.5 2026/10/21 20:44:54 ktnb Exp $

DISTNAME=	topgit-0.19.14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mackyle/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/mackyle/topgit
COMMENT=	Different patch queue manager
LICENSE=	gnu-gpl-v2

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

WRKSRC=		${WRKDIR}/${PKGBASE}-${PKGNAME_NOREV}
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake perl

MAKE_ENV+=	prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
