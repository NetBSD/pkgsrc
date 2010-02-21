# $NetBSD: Makefile,v 1.14 2010/02/21 15:07:40 wiz Exp $
#

DISTNAME=		par2cmdline-0.4
PKGNAME=		${DISTNAME:S/cmdline//}
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=parchive/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://parchive.sourceforge.net/
COMMENT=		Create or use PAR2 parity volumes
LICENSE=		gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
