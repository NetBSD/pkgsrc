# $NetBSD: Makefile,v 1.41 2026/11/19 12:39:01 adam Exp $

DISTNAME=	spandsp-3.1.1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=freeswitch/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/freeswitch/spandsp
COMMENT=	DSP library for telephony
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf gsed pkg-config
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	spandsp.pc.in

INSTALLATION_DIRS=	share/doc/${PKGBASE}

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

post-install:
	${INSTALL_DATA} ${WRKSRC}/DueDiligence ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
