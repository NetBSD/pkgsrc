# $NetBSD: Makefile,v 1.21 2009/06/30 00:07:11 joerg Exp $
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

.include "../../mk/bsd.pkg.mk"
