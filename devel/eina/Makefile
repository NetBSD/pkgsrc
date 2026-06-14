# $NetBSD: Makefile,v 1.14 2026/06/14 13:03:52 nia Exp $
#

DISTNAME=	eina-1.7.10
CATEGORIES=	devel
MASTER_SITES=	https://download.enlightenment.org/att/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://enlightenment.org/
COMMENT=	Data types library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
FORCE_C_STD=	gnu89

PKGCONFIG_OVERRIDE=	eina.pc.in

.include "../../mk/compiler.mk"

.if empty(PKGSRC_COMPILER:Msunpro)
BUILDLINK_TRANSFORM+=	rm:-mt
.endif

.include "../../mk/bsd.pkg.mk"
