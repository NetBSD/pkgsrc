# $NetBSD: Makefile,v 1.4 2019/05/13 13:58:53 mef Exp $

DISTNAME=	cloc-1.76
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AlDanial/}
GITHUB_PROJECT=	cloc
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

NO_BUILD=	yes
BUILD_DIRS=	Unix

.include "../../mk/bsd.pkg.mk"
