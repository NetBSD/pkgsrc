# $NetBSD: Makefile,v 1.4 2003/05/05 19:05:08 jmmv Exp $
#

DISTNAME=	JESS-2.9.1
PKGNAME=	xmms-jess-2.9.1
PKGREVISION=	1
CATEGORIES=	xmms audio
MASTER_SITES=	http://arquier.free.fr/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://arquier.free.fr/
COMMENT=	XMMS plugin with Blur, image distortion, and others

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../audio/xmms/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
