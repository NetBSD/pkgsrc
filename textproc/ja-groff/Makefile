# $NetBSD: Makefile,v 1.1.1.1 2002/05/31 13:00:40 seb Exp $
# FreeBSD Id: Makefile,v 1.15 1999/01/27 07:41:16 fenner Exp $

DISTNAME=	groff-1.10
PKGNAME=	ja-groff-0.99
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

PATCH_SITES=	ftp://ftp.ae.keio.ac.jp/pub/GNU/ \
		ftp://ftp.tohoku.ac.jp/pub/GNU/japanese/
PATCHFILES=	jgroff-0.99.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/groff/groff.html
COMMENT=	Japanese enhancement of GNU groff

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
#CONFIGURE_ENV+= CXXFLAGS="-fno-rtti -fno-exceptions -O"

.include "../../mk/bsd.pkg.mk"
