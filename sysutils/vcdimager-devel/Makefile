# $NetBSD: Makefile,v 1.12 2003/12/24 09:53:50 jmmv Exp $
#

DISTNAME=	vcdimager-0.7.12
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/vcdimager/

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/vcdimager/
COMMENT=	Mastering suite for Video CDs

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE= ${WRKSRC}/libtool
INFO_FILES=	vcdimager.info

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
