# $NetBSD: Makefile,v 1.11 2004/05/11 05:09:58 minskim Exp $
#

DISTNAME=	libcdio-0.68
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=libcdio/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libcdio/
COMMENT=	CD-ROM access library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libcdio.pc.in
PKGCONFIG_OVERRIDE+=	libiso9660.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-versioned-libs

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# XXX we just replace the freebsd module so save patches
pre-patch:
	${CP} ${FILESDIR}/_cdio_netbsd.c ${WRKSRC}/lib/_cdio_freebsd.c
.endif

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
