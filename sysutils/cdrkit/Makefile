# $NetBSD: Makefile,v 1.4 2008/12/02 13:03:22 obache Exp $
#

DISTNAME=	cdrkit-1.1.6
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://cdrkit.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cdrkit.org/
COMMENT=	Portable command-line CD/DVD recorder software

CONFLICTS=	cdrtools-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake perl:run
USE_LANGUAGES=	c c++
MAKE_FLAGS+=	MANSUBDIR=man

REPLACE_PERL=	3rd-party/dirsplit/dirsplit

.include "../../devel/cmake/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
