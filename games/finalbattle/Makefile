# $NetBSD: Makefile,v 1.19 2017/08/01 17:40:11 wiz Exp $
#

DISTNAME=	finalbattle.0.0
PKGNAME=	finalbattle-0.0
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=games/}
MASTER_SITES+=	ftp://ftp.billsgames.com/unix/x/finalbattle/

PATCH_SITES=	http://www.NetBSD.org/~dholland/patchkits/finalbattle/
PATCHFILES=	finalbattle-jumbo-patch-20161210.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://web.archive.org/web/2/http://www.newbreedsoftware.com/finalbattle/
COMMENT=	Multiplayer space battle simulation for X

WRKSRC=		${WRKDIR}/final
MAKE_FILE=	makefile

INSTALLATION_DIRS+=	bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
