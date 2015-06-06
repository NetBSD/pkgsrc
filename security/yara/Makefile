# $NetBSD: Makefile,v 1.1 2015/06/06 08:18:17 pettai Exp $

DISTNAME=	v3.3.0
PKGNAME=	yara-3.3.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=plusvic/yara/archive/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://plusvic.github.io/yara/
COMMENT=	Pattern matching swiss knife for malware researchers
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/yara-3.3.0
USE_TOOLS+=	pkg-config automake autoreconf
USE_LIBTOOL=	yes
GNU_CONFIGURE=          yes

PKGCONFIG_OVERRIDE+=	libyara/yara.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
