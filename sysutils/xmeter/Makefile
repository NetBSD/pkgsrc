# $NetBSD: Makefile,v 1.12 2008/07/14 12:56:13 joerg Exp $
#

DISTNAME=	xmeter-1.15
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=misdirected/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	#
COMMENT=	Distributed system load meter for X11

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
