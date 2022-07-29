# $NetBSD: Makefile,v 1.3 2022/07/29 16:29:09 jperkin Exp $

DISTNAME=	xcpc-20070122
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	https://bitbucket.org/ponceto/xcpc/get/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://bitbucket.org/ponceto/xcpc/get/
COMMENT=	Portable Amstrad CPC 464/664/6128 emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/ponceto-xcpc-90cd270f37be

USE_TOOLS+=	automake pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

LIBS.SunOS+=	-lintl

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/glib2/buildlink3.mk"
.include "../../emulators/libdsk/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
