# $NetBSD: Makefile,v 1.18 2007/12/31 07:37:46 obache Exp $
#

DISTNAME=	birda-1.3
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.augustsson.net/pub/netbsd/

MAINTAINER=	lennart@augustsson.net
COMMENT=	Bohlin's IrDA utilities

USE_BSD_MAKEFILE=	yes

MAKE_ENV+=		BINMODE=${BINMODE}
MAKE_ENV+=		MANMODE=${MANMODE}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
