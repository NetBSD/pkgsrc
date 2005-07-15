# $NetBSD: Makefile,v 1.54 2005/07/15 20:14:03 jlam Exp $

DISTNAME=		bison-2.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=bison/}

MAINTAINER=		cjep@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/bison/bison.html
COMMENT=		GNU yacc(1) replacement

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_USES_MSGFMT=	yes
GNU_CONFIGURE=		YES
USE_TOOLS+=		gm4:run

INFO_FILES=		bison.info

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
