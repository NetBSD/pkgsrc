# $NetBSD: Makefile,v 1.1.1.1 2004/01/17 14:38:22 recht Exp $
#

DISTNAME=	libcdio-0.65
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=libcdio/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libcdio/
COMMENT=	CD-ROM access library

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libcdio.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libiso9660.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
