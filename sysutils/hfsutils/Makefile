# $NetBSD: Makefile,v 1.8 2005/04/05 10:43:22 wiz Exp $
#

DISTNAME=	hfsutils-3.2.6
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/

MAINTAINER=	wrstuden@NetBSD.org
HOMEPAGE=	http://www.mars.org/home/rob/proj/hfs/
COMMENT=	Command Line Interface HFS (not HFS+) disk access tools

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include/libhfs

BUILD_TARGET=	all_cli
INSTALL_TARGET=	install_cli

.include "../../devel/libhfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
