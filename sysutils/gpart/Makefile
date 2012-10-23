# $NetBSD: Makefile,v 1.15 2012/10/23 19:51:05 asau Exp $

DISTNAME=	gpart-0.1h
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.stud.uni-hannover.de/user/76201/gpart/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.brzitwa.de/mb/gpart/index.html
COMMENT=	Tool to show the partitions on a PC type harddisk
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

# Doesn't work on 1.4.x due to problems with dlopen
NOT_FOR_PLATFORM=	NetBSD-1.4*-*

.include "../../mk/bsd.pkg.mk"
