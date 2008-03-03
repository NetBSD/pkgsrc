# $NetBSD: Makefile,v 1.2 2008/03/03 19:31:31 jlam Exp $
#

DISTNAME=	cddfs-0.2
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	http://castet.matthieu.free.fr/cddfs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://castet.matthieu.free.fr/cddfs/
COMMENT=	FUSE filesystem that uses libparanoia for audio CDs

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
BUILD_TARGET=		cddfs

BUILDLINK_FNAME_TRANSFORM.cdparanoia+=	-e "s|/cdparanoia/|/|g"

INSTALLATION_DIRS=	bin share/doc/fuse-cddfs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cddfs ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/fuse-cddfs

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
