# $NetBSD: Makefile,v 1.5 2003/06/02 01:16:55 jschauma Exp $

DISTNAME=	gpart-0.1g
CATEGORIES=	sysutils
MASTER_SITES=	http://home.pages.de/~michab/gpart/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://home.pages.de/~michab/gpart/
COMMENT=	Tool to show the partitions on a PC type harddisk

USE_GMAKE=	yes

# Doesn't work on 1.4.x due to problems with dlopen
NOT_FOR_PLATFORM=	NetBSD-1.4*-*

.include "../../mk/bsd.pkg.mk"
