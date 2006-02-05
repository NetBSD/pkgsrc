# $NetBSD: Makefile,v 1.20 2006/02/05 23:10:32 joerg Exp $

DISTNAME=	wistumbler-20020816
PKGNAME=	wistumbler-20020816.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://gongon.com/persons/iseki/wistumbler/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gongon.com/persons/iseki/wistumbler/
COMMENT=	Network stumbler for WaveLAN/IEEE wireless networking

WRKSRC=		${WRKDIR}/wistumbler

NOT_FOR_PLATFORM=	NetBSD-0.*-* NetBSD-1.[01234]*-* NetBSD-1.5-*
NOT_FOR_PLATFORM+=	NetBSD-1.5.*-* NetBSD-1.5[A-V]-*
NOT_FOR_PLATFORM+=	Interix-*-*

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
