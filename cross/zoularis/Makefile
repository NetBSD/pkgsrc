# $NetBSD: Makefile,v 1.15 2001/07/04 21:05:03 christos Exp $
#

DISTNAME=       zoularis-20010704
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.netbsd.org/
COMMENT=	provides NetBSD libs, includes and utilities on Solaris and Linux

WRKSRC=		${WRKDIR}/bsd

NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_PACKAGE=	This package is needed to compile the pkgtools

post-extract:
	@${ECHO} "Make sure /usr/ccs/bin is in your PATH and then"
	@${ECHO} "configure --srcdir /your/bsd/source/root \\"
	@${ECHO} "--prefix /your/installation/dir && make"

.include "../../mk/bsd.pkg.mk"
