# $NetBSD: Makefile,v 1.8 2003/08/09 10:44:50 seb Exp $
#

DISTNAME=	vcdimager-0.7.12
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/vcdimager/

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://www.gnu.org/software/vcdimager/
COMMENT=	Mastering suite for Video CDs

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE= ${WRKSRC}/libtool
INFO_FILES=	vcdimager.info

.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
