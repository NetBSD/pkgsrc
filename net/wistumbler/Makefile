# $NetBSD: Makefile,v 1.8 2003/05/02 11:56:12 wiz Exp $

DISTNAME=	wistumbler-20020811-2
PKGREVISION=	1
PKGNAME=	wistumbler-20020811.2
WRKSRC=		${WRKDIR}/wistumbler
CATEGORIES=	net
MASTER_SITES=	http://gongon.com/persons/iseki/wistumbler/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gongon.com/persons/iseki/wistumbler/
COMMENT=	Network stumbler for WaveLAN/IEEE wireless networking

USE_BUILDLINK2=	YES
USE_X11=	YES

NOT_FOR_PLATFORM=	NetBSD-0.*-* NetBSD-1.[01234]*-* NetBSD-1.5-*
NOT_FOR_PLATFORM+=	NetBSD-1.5.*-* NetBSD-1.5[A-V]-*

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
