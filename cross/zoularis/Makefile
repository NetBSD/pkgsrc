# $NetBSD: Makefile,v 1.5 1999/04/12 14:54:00 agc Exp $
#

DISTNAME=       zoularis-19990412
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.netbsd.org/

WRKSRC=		${WRKDIR}/bsd

NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_PACKAGE=	This package is needed to compile the pkgtools

post-extract:
	@${ECHO} "Please set BSDSRCDIR and DESTDIR in Makefile.inc"
	@${ECHO} "and make sure /usr/ccs/bin is in your PATH and then"
	@${ECHO} "/usr/ccs/bin/make"

.include "../../mk/bsd.pkg.mk"
