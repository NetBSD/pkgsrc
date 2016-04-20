# $NetBSD: Makefile,v 1.33 2016/04/20 12:10:35 nros Exp $

DISTNAME=	xmradio-1.2
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://core.de/~coto/radio/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://core.de/~coto/xmradio.html
COMMENT=	Radio application for Brooktree 848 compatible TV cards
LICENSE=	2-clause-bsd

DEPENDS+=	sox>=12.16:../../audio/sox

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-i386 \
			NetBSD-1.5_ALPHA-i386 NetBSD-1.[5-9]*-* \
			NetBSD-[2-9]*.*-* \
			DragonFly-*-*

USE_IMAKE=	YES

INSTALLATION_DIRS=	share/doc/xmradio

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xmradio

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
