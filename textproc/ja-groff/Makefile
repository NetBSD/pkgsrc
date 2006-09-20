# $NetBSD: Makefile,v 1.10 2006/09/20 10:59:40 hira Exp $

DISTNAME=	groff-1.10
PKGNAME=	ja-groff-0.99
PKGREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

PATCH_SITES=	ftp://ftp.ae.keio.ac.jp/pub/GNU/ \
		ftp://ftp.tohoku.ac.jp/pub/GNU/japanese/
PATCHFILES=	jgroff-0.99.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/groff/groff.html
COMMENT=	Japanese enhancement of GNU groff

USE_TOOLS+=	gmake perl:run
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
CONFIGURE_HAS_MANDIR=	no
#CONFIGURE_ENV+= CXXFLAGS="-fno-rtti -fno-exceptions -O"

REPLACE_PERL=	grog/grog.pl
REPLACE_PERL+=	afmtodit/afmtodit.pl

.include "../../mk/bsd.pkg.mk"
