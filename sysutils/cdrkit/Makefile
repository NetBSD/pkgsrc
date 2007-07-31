# $NetBSD: Makefile,v 1.2 2007/07/31 11:38:33 joerg Exp $
#

DISTNAME=	cdrkit-1.1.6
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://cdrkit.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cdrkit.org/
COMMENT=	Portable command-line CD/DVD recorder software

USE_TOOLS+=	gmake perl:run
USE_LANGUAGES=	c c++
MAKE_FLAGS+=	MANSUBDIR=man

REPLACE_PERL=	3rd-party/dirsplit/dirsplit

.include "../../devel/cmake/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
