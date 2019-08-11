# $NetBSD: Makefile,v 1.43 2019/08/11 13:21:05 wiz Exp $

DISTNAME=	zoom-1.1.5
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	https://www.logicalshift.co.uk/unix/zoom/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.logicalshift.co.uk/unix/zoom/
COMMENT=		Plays Infocom-compatible games, with graphics support
LICENSE=		gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
AUTO_MKDIRS=		yes

.if ${MACHINE_ARCH} == "alpha"
GCC_REQD+=		3.0
.endif
UNLIMIT_RESOURCES+=	datasize

post-install:
	cd ${WRKSRC}/manual \
	&& ${INSTALL_DATA} idx *.html *.gif *.png ${DESTDIR}${PREFIX}/share/doc/zoom

BUILDLINK_DEPMETHOD.libXt=	build

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
