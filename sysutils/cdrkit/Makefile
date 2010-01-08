# $NetBSD: Makefile,v 1.6 2010/01/08 16:19:18 joerg Exp $
#

DISTNAME=	cdrkit-1.1.9
CATEGORIES=	sysutils
MASTER_SITES=	http://cdrkit.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cdrkit.org/
COMMENT=	Portable command-line CD/DVD recorder software

CONFLICTS=	cdrtools-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_TOOLS+=	perl:run
USE_LANGUAGES=	c c++
CMAKE_ARGS+=	-DMANSUBDIR=${PKGMANDIR}

REPLACE_PERL=	3rd-party/dirsplit/dirsplit

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
