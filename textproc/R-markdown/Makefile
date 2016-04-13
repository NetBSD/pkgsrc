# $NetBSD: Makefile,v 1.2 2016/04/13 14:18:23 wen Exp $

CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/markdown/
COMMENT=	Markdown rendering for R
LICENSE=	gnu-gpl-v2

R_PKGNAME=	markdown
R_PKGVER=	0.7.7

DEPENDS+=	R-mime>=0.3:../../mail/R-mime

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
