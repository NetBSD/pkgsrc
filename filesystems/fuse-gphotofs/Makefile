# $NetBSD: Makefile,v 1.7 2012/03/03 00:13:03 wiz Exp $
#

DISTNAME=	gphotofs-0.4.0
PKGREVISION=	4
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
EXTRACT_SUFX=	.tar.bz2
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gphoto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gphoto.sourceforge.net/proj/gphotofs/
COMMENT=	FUSE filesystem for accessing digital cameras

PKG_DESTDIR_SUPPORT=	user-destdir

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
