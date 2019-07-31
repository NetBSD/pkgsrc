# $NetBSD: Makefile,v 1.4 2019/07/31 20:54:53 brook Exp $

CATEGORIES=	textproc R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/markdown/
COMMENT=	Render Markdown with the C Library 'Sundown'
LICENSE=	gnu-gpl-v2

R_PKGNAME=	markdown
R_PKGVER=	1.0

DEPENDS+=	R-mime>=0.3:../../mail/R-mime

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
