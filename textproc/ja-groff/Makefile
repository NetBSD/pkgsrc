# $NetBSD: Makefile,v 1.6 2005/10/08 22:06:46 hira Exp $

DISTNAME=	groff-1.10
PKGNAME=	ja-groff-0.99
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

PATCH_SITES=	ftp://ftp.ae.keio.ac.jp/pub/GNU/ \
		ftp://ftp.tohoku.ac.jp/pub/GNU/japanese/
PATCHFILES=	jgroff-0.99.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/groff/groff.html
COMMENT=	Japanese enhancement of GNU groff

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
CONFIGURE_HAS_MANDIR=	no
#CONFIGURE_ENV+= CXXFLAGS="-fno-rtti -fno-exceptions -O"

.include "../../mk/bsd.pkg.mk"
