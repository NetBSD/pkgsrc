# $NetBSD: Makefile,v 1.14 2005/02/21 20:26:09 hubertf Exp $
#

DISTNAME=	tv_scope-0.0.2
PKGNAME=	xmms-tv-scope-0.0.2
PKGREVISION=	4
CATEGORIES=	xmms audio
MASTER_SITES=	http://staff.xmms.org/zinx/xmms/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://staff.xmms.org/zinx/xmms/
COMMENT=	3D Representation of a waveform

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

ONLY_FOR_PLATFORM=	SunOS-*-* Linux-*-* Darwin-*-*
ONLY_FOR_PLATFORM+=	NetBSD-1.6[N-Z]-* NetBSD-1.6Z[A-Z]-*
ONLY_FOR_PLATFORM+=	NetBSD-[2-9]*

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
