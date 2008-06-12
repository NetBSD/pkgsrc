# $NetBSD: Makefile,v 1.13 2008/06/12 02:14:13 joerg Exp $
#

DISTNAME=		par2cmdline-0.4
PKGNAME=		${DISTNAME:S/cmdline//}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=parchive/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://parchive.sourceforge.net/
COMMENT=		Create or use PAR2 parity volumes

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
