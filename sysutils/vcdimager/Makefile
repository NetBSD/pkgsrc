# $NetBSD: Makefile,v 1.25 2012/10/23 19:51:29 asau Exp $
#

DISTNAME=	vcdimager-0.6.2
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=vcdimager/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/vcdimager/
COMMENT=	Mastering suite for Video CDs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
INFO_FILES=	# PLIST

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
