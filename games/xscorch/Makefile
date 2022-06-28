# $NetBSD: Makefile,v 1.39 2022/06/28 11:33:57 wiz Exp $

DISTNAME=	xscorch_0.2.1.orig
PKGNAME=	${DISTNAME:S/_/-/1:S/.orig//1}
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xscorch/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20200117143419/http://www.xscorch.org/
COMMENT=	Multiplayer tank shoot-em-up
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LIBTOOL=		YES
USE_TOOLS+=		perl pkg-config
GNU_CONFIGURE=		YES

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
