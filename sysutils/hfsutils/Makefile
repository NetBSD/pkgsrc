# $NetBSD: Makefile,v 1.12 2017/08/16 20:21:14 wiz Exp $
#

DISTNAME=	hfsutils-3.2.6
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mars.org/home/rob/proj/hfs/
COMMENT=	Command Line Interface HFS (not HFS+) disk access tools

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include/libhfs

BUILD_TARGET=	all_cli
INSTALL_TARGET=	install_cli
INSTALL_MAKE_FLAGS+=	BINDEST=${DESTDIR}${PREFIX}/bin \
			MANDEST=${DESTDIR}${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/libhfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
