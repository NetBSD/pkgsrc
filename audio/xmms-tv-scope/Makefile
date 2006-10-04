# $NetBSD: Makefile,v 1.22 2006/10/04 20:44:20 wiz Exp $
#

DISTNAME=	tv_scope-0.0.2
PKGNAME=	xmms-tv-scope-0.0.2
PKGREVISION=	8
CATEGORIES=	xmms audio
MASTER_SITES=	http://zinx.xmms.org/xmms/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zinx.xmms.org/xmms/
COMMENT=	3D Representation of a waveform

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

ONLY_FOR_PLATFORM=	SunOS-*-* Linux-*-* Darwin-*-*
ONLY_FOR_PLATFORM+=	NetBSD-1.6[N-Z]-* NetBSD-1.6Z[A-Z]-*
ONLY_FOR_PLATFORM+=	NetBSD-[2-9]*-*

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
