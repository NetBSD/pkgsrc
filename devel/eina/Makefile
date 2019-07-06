# $NetBSD: Makefile,v 1.10 2019/07/06 16:46:09 nia Exp $
#

DISTNAME=	eina-1.7.7
CATEGORIES=	devel
MASTER_SITES=	http://download.enlightenment.org/releases/
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
