# $NetBSD: Makefile,v 1.11 2025/11/17 11:00:34 wiz Exp $

DISTNAME=	CUnit-2.1-3
PKGNAME=	CUnit-2.1.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cunit/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cunit.sourceforge.net/
COMMENT=	C Unit checking test software
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake autoreconf
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	cunit.pc.in

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
