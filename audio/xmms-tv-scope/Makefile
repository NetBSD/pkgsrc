# $NetBSD: Makefile,v 1.1.1.1 2003/02/14 23:56:39 hubertf Exp $
#

DISTNAME=	tv_scope-0.0.2
PKGNAME=	xmms-tv-scope-0.0.2
CATEGORIES=	xmms audio
MASTER_SITES=	http://staff.xmms.org/zinx/xmms/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://staff.xmms.org/zinx/xmms/
COMMENT=	3D Representation of a waveform

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../audio/xmms/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
