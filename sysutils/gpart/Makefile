# $NetBSD: Makefile,v 1.8 2004/01/31 22:56:11 xtraeme Exp $

DISTNAME=	gpart-0.1h
CATEGORIES=	sysutils
MASTER_SITES=	http://home.pages.de/~michab/gpart/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://home.pages.de/~michab/gpart/
COMMENT=	Tool to show the partitions on a PC type harddisk

USE_GNU_TOOLS+=	make

# Doesn't work on 1.4.x due to problems with dlopen
NOT_FOR_PLATFORM=	NetBSD-1.4*-*

.include "../../mk/bsd.pkg.mk"
