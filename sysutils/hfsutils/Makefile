# $NetBSD: Makefile,v 1.3 2001/02/17 17:42:14 wiz Exp $
#

DISTNAME=	hfsutils-3.2.6
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/

MAINTAINER=	wrstuden@netbsd.org
HOMEPAGE=	http://www.mars.org/home/rob/proj/hfs/
COMMENT=	Command Line Interface HFS (not HFS+) disk access tools

DEPENDS=	libhfs-3.2.6:../../devel/libhfs

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include/libhfs

ALL_TARGET=	all_cli
INSTALL_TARGET=	install_cli

.include "../../mk/bsd.pkg.mk"
