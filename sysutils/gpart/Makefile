# $NetBSD: Makefile,v 1.13 2010/02/04 21:14:02 heinz Exp $

DISTNAME=	gpart-0.1h
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.stud.uni-hannover.de/user/76201/gpart/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stud.uni-hannover.de/user/76201/gpart/
COMMENT=	Tool to show the partitions on a PC type harddisk
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake

# Doesn't work on 1.4.x due to problems with dlopen
NOT_FOR_PLATFORM=	NetBSD-1.4*-*

.include "../../mk/bsd.pkg.mk"
