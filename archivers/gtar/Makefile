# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:08 agc Exp $
#

DISTNAME=       tar-1.12
PKGNAME=	gtar-1.12
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

OPSYS!= uname -s
.if (${OPSYS} == "NetBSD")
BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
.endif

GNU_CONFIGURE=yes
CONFIGURE_ARGS= --program-prefix=g

MAN1=	gtar.1

post-install:
	${INSTALL_DATA} ${FILESDIR}/gtar.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
