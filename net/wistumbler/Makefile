# $NetBSD: Makefile,v 1.6 2002/09/09 18:09:57 wiz Exp $

DISTNAME=	wistumbler-20020811-2
PKGNAME=	wistumbler-20020811.2
CATEGORIES=	net
MASTER_SITES=	http://gongon.com/persons/iseki/wistumbler/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gongon.com/persons/iseki/wistumbler/
COMMENT=	Network stumbler for WaveLAN/IEEE wireless networking

USE_BUILDLINK2=	YES
USE_X11=	YES

WRKSRC=		${WRKDIR}/wistumbler

NOT_FOR_PLATFORM=	NetBSD-0.*-* NetBSD-1.[01234]*-* NetBSD-1.5-*
NOT_FOR_PLATFORM+=	NetBSD-1.5.*-* NetBSD-1.5[A-V]-*

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
