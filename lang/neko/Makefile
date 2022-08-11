# $NetBSD: Makefile,v 1.15 2022/08/11 06:41:57 wiz Exp $

DISTNAME=	neko-2.3.0
PKGREVISION=	11
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=HaxeFoundation/}
GITHUB_TAG=	v${PKGVERSION_NOREV:S/./-/g}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://nekovm.org/
COMMENT=	High-level dynamically typed programming language
LICENSE=	mit

TOOL_DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

# Tries to build "bin/nekoc.n, bin/nekoml.n" multiple times at once
# and then chokes because nekoc.n won't load. Examination shows that
# the makefiles spewed from cmake try to build this element from four
# different subdirs at once, which is obviously unsafe, and arguing
# with cmake about this sort of thing is a waste of breath.
MAKE_JOBS_SAFE=	no

.include "options.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
