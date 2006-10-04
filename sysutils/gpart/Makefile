# $NetBSD: Makefile,v 1.12 2006/10/04 21:59:34 wiz Exp $

DISTNAME=	gpart-0.1h
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.stud.uni-hannover.de/user/76201/gpart/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stud.uni-hannover.de/user/76201/gpart/
COMMENT=	Tool to show the partitions on a PC type harddisk

USE_TOOLS+=	gmake

# Doesn't work on 1.4.x due to problems with dlopen
NOT_FOR_PLATFORM=	NetBSD-1.4*-*

.include "../../mk/bsd.pkg.mk"
