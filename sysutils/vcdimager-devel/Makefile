# $NetBSD: Makefile,v 1.4 2003/07/13 13:53:23 wiz Exp $
#

DISTNAME=	vcdimager-0.7.12
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/vcdimager/

MAINTAINER=	collver1@attbi.com
HOMEPAGE=	http://www.gnu.org/software/vcdimager/
COMMENT=	mastering suite for Video CDs

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE= ${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
