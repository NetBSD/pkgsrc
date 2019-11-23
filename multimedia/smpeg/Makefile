# $NetBSD: Makefile,v 1.35 2019/11/23 23:03:01 nia Exp $

DISTNAME=	smpeg-0.4.5
CATEGORIES=	devel multimedia
MASTER_SITES=	#
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icculus.org/smpeg/
COMMENT=	SDL MPEG Player Library
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	aclocal automake autoconf gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-Dunix=1

LDFLAGS.SunOS+=	-shared -mimpure-text

CONFIGURE_ARGS+=	--disable-gtk-player
CONFIGURE_ARGS+=	--disable-sdltest

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

post-install:
	# gtk1 player is not installed
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gtv.1

.include "options.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
