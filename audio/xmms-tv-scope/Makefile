# $NetBSD: Makefile,v 1.3 2003/04/23 02:22:26 jmc Exp $
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

ONLY_FOR_PLATFORM=	SunOS-*-* Linux-*-* Darwin-*-* 
ONLY_FOR_PLATFORM+=	NetBSD-1.6[N-Z]-* NetBSD-1.6Z[A-Z]-* NetBSD-1.[7-9]*
ONLY_FOR_PLATFORM+=	NetBSD-[2-9]*

.include "../../audio/xmms/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
