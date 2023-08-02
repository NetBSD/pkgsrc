# $NetBSD: Makefile,v 1.31 2023/08/02 19:21:57 nia Exp $

DISTNAME=	groff-1.10
PKGNAME=	ja-groff-0.99
PKGREVISION=	12
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

PATCH_SITES=		ftp://ftp.ae.keio.ac.jp/pub/GNU/
PATCHFILES=		jgroff-0.99.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/groff/groff.html
COMMENT=	Japanese enhancement of GNU groff

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake perl:run yacc
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_HAS_MANDIR=	no
#CONFIGURE_ENV+=	CXXFLAGS="-fno-rtti -fno-exceptions -O"
MAKE_FLAGS+=		manroot=${DESTDIR}${PREFIX}/${PKGMANDIR}
INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			datadir=${DESTDIR}${PREFIX}/share

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

REPLACE_PERL=	grog/grog.pl
REPLACE_PERL+=	afmtodit/afmtodit.pl

# 'checking for working mmap...' conftest hangs
BROKEN_ON_PLATFORM+=	Darwin-*-aarch64

.include "../../mk/bsd.pkg.mk"
