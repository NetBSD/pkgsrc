# $NetBSD: Makefile,v 1.14 1998/08/02 19:30:51 tron Exp $
# FreeBSD Id: Makefile,v 1.16 1997/06/13 20:00:47 max Exp
#

DISTNAME=       make-3.77
PKGNAME=        gmake-3.77
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

CONFLICTS=	gmake-3.75 gmake-3.76.1

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

# joerg@freebsd.org says FreeBSD getloadavg() no longer requires setgid kmem
post-install:
	/bin/chmod g-s ${PREFIX}/bin/gmake
	/usr/bin/chgrp ${BINGRP} ${PREFIX}/bin/gmake

.include "../../mk/bsd.pkg.mk"
