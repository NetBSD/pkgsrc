# $NetBSD: Makefile,v 1.6 2004/04/08 18:52:33 drochner Exp $
#

DISTNAME=	libcdio-0.68
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=libcdio/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libcdio/
COMMENT=	CD-ROM access library

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libcdio.pc.in
PKGCONFIG_OVERRIDE+=	libiso9660.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-versioned-libs

# XXX we just replace the freebsd module so save patches
pre-patch:
	${CP} ${FILESDIR}/_cdio_netbsd.c ${WRKSRC}/lib/_cdio_freebsd.c

.include "../../devel/popt/buildlink2.mk"
.include "../../audio/libcddb/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
