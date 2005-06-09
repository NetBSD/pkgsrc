# $NetBSD: Makefile,v 1.17.4.1 2005/06/09 22:31:18 salo Exp $
#

DISTNAME=	gzip-1.2.4a
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/gzip-/gzip-base-/:S/a$/b/}
SVR4_PKGNAME=	gzipb
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=gzip/}
EXTRACT_SUFX=	.shar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	Compress or expand files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

BUILD_TARGET=	all manlinks=so
INSTALL_TARGET=	install manlinks=so

.include "../../mk/bsd.pkg.mk"
