# $NetBSD: Makefile,v 1.22 2012/02/16 16:40:34 hans Exp $
#

DISTNAME=	birda-1.3
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.augustsson.net/pub/netbsd/

MAINTAINER=	lennart@augustsson.net
COMMENT=	Bohlin's IrDA utilities

MAKE_JOBS_SAFE=		no

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

PKG_DESTDIR_SUPPORT=	user-destdir

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
