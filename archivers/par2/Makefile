# $NetBSD: Makefile,v 1.5 2005/01/21 21:48:32 tv Exp $
#

DISTNAME=		par2cmdline-0.3
PKGNAME=		${DISTNAME:S/cmdline//}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=parchive/}

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://parchive.sourceforge.net/
COMMENT=		Create or use PAR2 parity volumes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
