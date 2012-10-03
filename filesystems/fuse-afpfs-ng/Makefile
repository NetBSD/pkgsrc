# $NetBSD: Makefile,v 1.10 2012/10/03 16:08:30 asau Exp $

DISTNAME=	afpfs-ng-0.8.1
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=afpfs-ng/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/afpfs-ng
COMMENT=	FUSE filesystem for network mounting using AFP

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

REPLACE_SH+=	fuse/afpfs

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
