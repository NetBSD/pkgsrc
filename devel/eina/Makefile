# $NetBSD: Makefile,v 1.12 2020/05/01 00:01:32 joerg Exp $
#

DISTNAME=	eina-1.7.10
CATEGORIES=	devel
MASTER_SITES=	https://download.enlightenment.org/att/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://enlightenment.org/
COMMENT=	Data types library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	eina.pc.in

.include "../../mk/compiler.mk"

.if empty(PKGSRC_COMPILER:Msunpro)
BUILDLINK_TRANSFORM+=	rm:-mt
.endif

.include "../../mk/bsd.pkg.mk"
