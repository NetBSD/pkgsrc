# $NetBSD: Makefile,v 1.1 2025/06/02 07:45:16 vins Exp $

DISTNAME=	${PKGNAME:S/-//}
PKGNAME=	mxascii-1.1
CATEGORIES=	misc
MASTER_SITES=	https://www.muquit.com/muquit/software/mxascii/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.muquit.com/muquit/software/mxascii//mxascii.html
COMMENT=	X/Motif utility to display an ASCII table
LICENSE=	hpnd

USE_IMAKE=	yes

MAKE_FLAGS+=	CC=${CC:Q}		\
		PREFIX=${PREFIX}	\
		CCOPTIONS=${CFLAGS:Q}	\
		LOCAL_LDFLAGS=${LDFLAGS:Q}

BUILD_TARGET=	${PKGBASE}
INSTALL_TARGET=	common-install

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
