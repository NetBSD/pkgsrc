# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:59 tv Exp $
#

DISTNAME=		cdl3-1.2.4
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.kun.nl/pub/cdl3/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jaapboen@sci.kun.nl
HOMEPAGE=		http://www.cs.kun.nl/~kees/cdl3/
COMMENT=		Programming language for the development of compilers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
