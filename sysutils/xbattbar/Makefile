# $NetBSD: Makefile,v 1.41 2025/09/13 18:52:08 tsutsui Exp $

DISTNAME=	xbattbar_1.4.2
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	12
CATEGORIES=	sysutils x11
#MASTER_SITES=	http://iplab.aist-nara.ac.jp/member/suguru/
MASTER_SITES=	https://www.minix3.org/distfiles-backup/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20160729024814/http://iplab.naist.jp/member/suguru/xbattbar.html
COMMENT=	X11 battery graph for laptops
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	Linux-*-*

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

USE_IMAKE=	yes

.if !exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=	-D_NO_APM
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
