# $NetBSD: Makefile,v 1.57 2006/03/30 03:44:42 jlam Exp $

DISTNAME=		bison-2.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=bison/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		cjep@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/bison/bison.html
COMMENT=		GNU yacc(1) replacement

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_USES_MSGFMT=	yes
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gm4:run
INFO_FILES=		# PLIST

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
