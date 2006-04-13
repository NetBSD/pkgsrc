# $NetBSD: Makefile,v 1.58 2006/04/13 18:23:31 jlam Exp $

DISTNAME=		bison-2.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=bison/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		cjep@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/bison/bison.html
COMMENT=		GNU yacc(1) replacement

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gm4:run msgfmt
INFO_FILES=		# PLIST

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
