# $NetBSD: Makefile,v 1.15 2004/05/07 21:41:43 reed Exp $
#

DISTNAME=	gzip-1.2.4a
PKGNAME=	${DISTNAME:S/gzip-/gzip-base-/}
PKGREVISION=	1
SVR4_PKGNAME=	gzipb
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=gzip/}
EXTRACT_SUFX=	.shar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	Compress or expand files

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

BUILD_TARGET=	all manlinks=so
INSTALL_TARGET=	install manlinks=so

.include "../../mk/bsd.pkg.mk"
