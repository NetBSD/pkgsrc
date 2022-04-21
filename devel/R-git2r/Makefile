# $NetBSD: Makefile,v 1.4 2022/04/21 13:59:08 mef Exp $

R_PKGNAME=	git2r
R_PKGVER=	0.30.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provides access to Git repositories
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	R-getPass-[0-9]*:../../security/R-getPass
#EST_DEPENDS+=	libgit2-[0-9]*:../../devel/libgit2

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
