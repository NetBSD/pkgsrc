# $NetBSD: Makefile,v 1.1 2014/09/19 22:44:40 brook Exp $

CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/markdown/
COMMENT=	Markdown rendering for R
LICENSE=	gnu-gpl-v2

R_PKGNAME=	markdown
R_PKGVER=	0.7.4

DEPENDS+=	R-mime>=0.1.1:../../mail/R-mime

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
