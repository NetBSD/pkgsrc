# $NetBSD: Makefile,v 1.15 2004/10/03 00:18:01 tv Exp $

DISTNAME=	wistumbler-20020816
PKGNAME=	wistumbler-20020816.0
PKGREVISION=			2
CATEGORIES=	net
MASTER_SITES=	http://gongon.com/persons/iseki/wistumbler/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gongon.com/persons/iseki/wistumbler/
COMMENT=	Network stumbler for WaveLAN/IEEE wireless networking

WRKSRC=		${WRKDIR}/wistumbler
USE_BUILDLINK3=	YES
USE_X11=	YES

NOT_FOR_PLATFORM=	NetBSD-0.*-* NetBSD-1.[01234]*-* NetBSD-1.5-*
NOT_FOR_PLATFORM+=	NetBSD-1.5.*-* NetBSD-1.5[A-V]-*

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
