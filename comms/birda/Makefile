# $NetBSD: Makefile,v 1.25 2021/04/21 09:04:33 wiz Exp $

DISTNAME=	birda-1.3
PKGREVISION=	1
CATEGORIES=	comms
#MASTER_SITES=	ftp://ftp.augustsson.net/pub/netbsd/

MAINTAINER=	lennart@augustsson.net
COMMENT=	Bohlin's IrDA utilities

MAKE_JOBS_SAFE=		no

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
