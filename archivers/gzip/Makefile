# $NetBSD: Makefile,v 1.26 2013/06/09 16:55:08 ryoon Exp $
#

DISTNAME=	gzip-1.5
SVR4_PKGNAME=	gzip
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=gzip/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	Compress or expand files
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=		gzip-base-[0-9]* gzip-info-[0-9]*

GNU_CONFIGURE=	YES
MAKE_FLAGS+=	manlinks=so
INFO_FILES=	yes
CHECK_PERMS=	no	# can't depend on checkperms; it's distfile is gzipped

.include "../../mk/bsd.pkg.mk"
