# $NetBSD: Makefile,v 1.10 2003/08/05 21:22:36 seb Exp $
#

DISTNAME=	vcdimager-0.6.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=vcdimager/}

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://www.gnu.org/software/vcdimager/
COMMENT=	Mastering suite for Video CDs

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_NEW_TEXINFO=	YES
INFO_FILES=	vcdimager.info

.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
