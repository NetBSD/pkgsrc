# $NetBSD: Makefile,v 1.20 2001/06/25 23:58:32 zuntum Exp $
#

DISTNAME=       xart19980415
PKGNAME=	xart-19980415
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.cqi.com/~humbubba/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cqi.com/~humbubba/linux.html
COMMENT=	Paint program (enhanced xpaint)

USE_BUILDLINK_ONLY=YES
USE_IMAKE=      YES
USE_XPM=	YES

WRKSRC=		${WRKDIR}/19980415

post-extract:
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${FIND} ${WRKSRC} -type f -print | ${XARGS} ${CHMOD} 644

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
