# $NetBSD: Makefile,v 1.11 2006/03/04 21:30:41 jlam Exp $

DISTNAME=	gpart-0.1h
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://home.pages.de/~michab/gpart/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.pages.de/~michab/gpart/
COMMENT=	Tool to show the partitions on a PC type harddisk

USE_TOOLS+=	gmake

# Doesn't work on 1.4.x due to problems with dlopen
NOT_FOR_PLATFORM=	NetBSD-1.4*-*

.include "../../mk/bsd.pkg.mk"
