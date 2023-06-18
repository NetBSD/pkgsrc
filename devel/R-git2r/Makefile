# $NetBSD: Makefile,v 1.5 2023/06/18 13:50:31 mef Exp $

R_PKGNAME=	git2r
R_PKGVER=	0.32.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provides access to Git repositories
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	R-getPass-[0-9]*:../../security/R-getPass
#EST_DEPENDS+=	libgit2-[0-9]*:../../devel/libgit2

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
