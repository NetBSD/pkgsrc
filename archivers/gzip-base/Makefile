# $NetBSD: Makefile,v 1.21 2006/02/09 18:29:01 rillig Exp $
#

DISTNAME=	gzip-1.2.4a
PKGNAME=	${DISTNAME:S/gzip-/gzip-base-/:S/a$/b/}
PKGREVISION=	1
SVR4_PKGNAME=	gzipb
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=gzip/}
EXTRACT_SUFX=	.shar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	Compress or expand files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
MAKE_FLAGS+=	manlinks=so

.include "../../mk/bsd.pkg.mk"
