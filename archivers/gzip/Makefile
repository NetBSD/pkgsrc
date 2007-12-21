# $NetBSD: Makefile,v 1.20 2007/12/21 23:21:12 joerg Exp $
#

DISTNAME=	gzip-1.3.12
PKGREVISION=	1
SVR4_PKGNAME=	gzip
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=gzip/}
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	Compress or expand files

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		gzip-base-[0-9]* gzip-info-[0-9]*

GNU_CONFIGURE=	YES
MAKE_FLAGS+=	manlinks=so
INFO_FILES=	gzip.info

.include "../../mk/bsd.pkg.mk"
