# $NetBSD: Makefile,v 1.14 2001/02/16 14:05:08 wiz Exp $
#

DISTNAME=       zoularis-20001003
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.netbsd.org/
COMMENT=	provides NetBSD libs, includes and utilities on Solaris

WRKSRC=		${WRKDIR}/bsd

NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_PACKAGE=	This package is needed to compile the pkgtools

post-extract:
	@${ECHO} "Please set BSDSRCDIR and DESTDIR in Makefile.inc"
	@${ECHO} "and make sure /usr/ccs/bin is in your PATH and then"
	@${ECHO} "/usr/ccs/bin/make"

.include "../../mk/bsd.pkg.mk"
