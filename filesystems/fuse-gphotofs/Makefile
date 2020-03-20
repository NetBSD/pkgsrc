# $NetBSD: Makefile,v 1.14 2020/03/20 11:57:37 nia Exp $

DISTNAME=	gphotofs-0.5
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/gphotofs/
COMMENT=	FUSE filesystem for accessing digital cameras
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS=	share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
