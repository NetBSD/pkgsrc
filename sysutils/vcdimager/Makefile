# $NetBSD: Makefile,v 1.17 2005/02/23 04:09:51 minskim Exp $
#

DISTNAME=	vcdimager-0.6.2
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=vcdimager/}

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/vcdimager/
COMMENT=	Mastering suite for Video CDs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
INFO_FILES=	vcdimager.info

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
