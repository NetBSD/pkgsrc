# $NetBSD: Makefile,v 1.6 2026/02/18 08:02:17 wiz Exp $

DISTNAME=	xcpc-20070122
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	https://bitbucket.org/ponceto/xcpc/get/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://bitbucket.org/ponceto/xcpc/src/master/
COMMENT=	Portable Amstrad CPC 464/664/6128 emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/ponceto-xcpc-90cd270f37be

USE_TOOLS+=	automake pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/glib2/buildlink3.mk"
.include "../../emulators/libdsk/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
