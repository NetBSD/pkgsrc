# $NetBSD: Makefile,v 1.9 1998/04/15 10:38:20 agc Exp $
# FreeBSD Id: Makefile,v 1.16 1997/06/13 20:00:47 max Exp
#

DISTNAME=       make-3.76.1
PKGNAME=        gmake-3.76.1
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

OPSYS!= 	uname -s
.if (${OPSYS} == "NetBSD")
BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
.endif

GNU_CONFIGURE=	yes
MAN1=		gmake.1

# joerg@freebsd.org says FreeBSD getloadavg() no longer requires setgid kmem
post-install:
	/bin/chmod g-s ${PREFIX}/bin/gmake
	/usr/bin/chgrp ${BINGRP} ${PREFIX}/bin/gmake
	cd ${WRKSRC} && \
		${INSTALL_MAN} ${WRKSRC}/make.man ${PREFIX}/man/man1/${MAN1}

.include "../../mk/bsd.pkg.mk"
