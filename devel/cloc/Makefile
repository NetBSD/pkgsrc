# $NetBSD: Makefile,v 1.15 2022/06/27 15:29:14 fcambus Exp $

DISTNAME=	cloc-1.92
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AlDanial/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AlDanial/cloc
COMMENT=	Count lines of code
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run gmake

DEPENDS+=	p5-Algorithm-Diff-[0-9]*:../../devel/p5-Algorithm-Diff
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-Parallel-ForkManager-[0-9]*:../../devel/p5-Parallel-ForkManager

REPLACE_PERL+=	Unix/cloc

MAKE_ENV+=	PODDATE=2021-05-01

NO_BUILD=	yes
BUILD_DIRS=	Unix

.include "../../mk/bsd.pkg.mk"
