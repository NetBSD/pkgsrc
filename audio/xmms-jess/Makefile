# $NetBSD: Makefile,v 1.1.1.1 2003/02/14 23:56:39 hubertf Exp $
#

DISTNAME=	JESS-2.9.1
PKGNAME=	xmms-jess-2.9.1
CATEGORIES=	xmms audio
MASTER_SITES=	http://arquier.free.fr/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://arquier.free.fr/
COMMENT=	XMMS plugin with Blur, image distorsion, etc.

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../audio/xmms/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
