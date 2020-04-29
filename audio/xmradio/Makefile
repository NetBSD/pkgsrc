# $NetBSD: Makefile,v 1.34 2020/04/29 19:44:49 maya Exp $

DISTNAME=	xmradio-1.2
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://core.de/~coto/radio/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://core.de/~coto/xmradio.html
COMMENT=	Radio application for Brooktree 848 compatible TV cards
LICENSE=	2-clause-bsd

DEPENDS+=	sox>=12.16:../../audio/sox

ONLY_FOR_PLATFORM=	NetBSD-*.*-* DragonFly-*-*

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
