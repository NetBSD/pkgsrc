# $NetBSD: Makefile,v 1.2 2001/02/17 17:42:14 wiz Exp $

DISTNAME=	gpart-0.1g
CATEGORIES=	sysutils
MASTER_SITES=	http://home.pages.de/~michab/gpart/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://home.pages.de/~michab/gpart/
COMMENT=	Tool to show the partitions on a PC type harddisk

USE_GMAKE=	yes

# Doesn't work on 1.4.x due too problems with dlopen
ONLY_FOR_PLATFORM=	NetBSD-1.5*-i386

.include "../../mk/bsd.pkg.mk"
