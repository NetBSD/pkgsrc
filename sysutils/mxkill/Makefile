# $NetBSD: Makefile,v 1.1 2025/06/02 11:16:23 vins Exp $

DISTNAME=	${PKGNAME:S/-//}
PKGNAME=	mxkill-1.2
CATEGORIES=	sysutils
MASTER_SITES=	https://www.muquit.com/muquit/software/mxkill/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.muquit.com/muquit/software/mxkill//mxkill.html
COMMENT=	X/Motif interface to ps
LICENSE=	hpnd

USE_IMAKE=	yes

MAKE_FLAGS+=	CC=${CC:Q} PREFIX=${PREFIX} \
		CCOPTIONS=${CFLAGS:Q} LOCAL_LDFLAGS=${LDFLAGS:Q}

BUILD_TARGET=	${PKGBASE}
INSTALL_TARGET=	common-install

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
