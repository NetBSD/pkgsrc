# $NetBSD: Makefile,v 1.24 2013/10/10 00:02:17 joerg Exp $
#

DISTNAME=	birda-1.3
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.augustsson.net/pub/netbsd/

MAINTAINER=	lennart@augustsson.net
COMMENT=	Bohlin's IrDA utilities

MAKE_JOBS_SAFE=		no

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
