# $NetBSD: Makefile,v 1.10 1999/08/30 05:22:00 christos Exp $
#

DISTNAME=       zoularis-19990830
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
