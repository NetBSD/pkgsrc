# $NetBSD: Makefile,v 1.3 2003/02/04 10:52:15 drochner Exp $
#

DISTNAME=	vcdimager-0.7.12
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
