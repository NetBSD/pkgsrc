# $NetBSD: Makefile,v 1.3 2002/10/17 13:28:05 agc Exp $

DISTNAME=	gpart-0.1g
CATEGORIES=	sysutils
MASTER_SITES=	http://home.pages.de/~michab/gpart/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://home.pages.de/~michab/gpart/
COMMENT=	Tool to show the partitions on a PC type harddisk

USE_GMAKE=	yes

# Doesn't work on 1.4.x due too problems with dlopen
ONLY_FOR_PLATFORM=	NetBSD-1.[5-9]*-i386

.include "../../mk/bsd.pkg.mk"
