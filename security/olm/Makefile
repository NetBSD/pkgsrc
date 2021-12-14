# $NetBSD: Makefile,v 1.2 2021/12/14 01:01:48 gdt Exp $

DISTNAME=	olm-3.2.8
CATEGORIES=	security
MASTER_SITES=	https://gitlab.matrix.org/matrix-org/olm/-/archive/3.2.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.matrix.org/matrix-org/olm
COMMENT=	Implementation of the Double Ratchet cryptographic ratchet
LICENSE=	apache-2.0

# Ah for the days when the distfile unpacked to the right place...
WRKSRC=		${WRKDIR}/olm-3.2.2-3745ea57bbce319ac2f190e02062e45a46d23471

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	olm.pc.in

.include "../../mk/bsd.pkg.mk"
