# $NetBSD: Makefile,v 1.5 2003/01/29 06:45:47 jlam Exp $

DISTNAME=	psi-0.8.7
CATEGORIES=	chat
MASTER_SITES=	http://belnet.dl.sourceforge.net/sourceforge/psi/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@netbsd.org
HOMEPAGE=	http://psi.affinix.com/
COMMENT=	PSI Jabber Client

# need qt3 3.0.4nb2, for qmake
BUILD_DEPENDS+=	qt3-tools>=3.0.4nb2:../../x11/qt3-tools

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes
HAS_CONFIGURE=	yes

BUILD_DIRS=	${WRKSRC}/src

CONFIGURE_ARGS+= -p ${PREFIX}

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
