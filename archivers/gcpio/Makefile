# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:07 agc Exp $
#

DISTNAME=       cpio-2.4.2
PKGNAME=	gcpio-2.4.2
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

OPSYS!= uname -s
.if (${OPSYS} == "NetBSD")
BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
.endif

GNU_CONFIGURE=yes
CONFIGURE_ARGS= --program-prefix=g
LDFLAGS=	-lgnumalloc

MAN1=	gcpio.1

post-install:
	install-info --info-dir=${PREFIX}/info ${PREFIX}/info/cpio.info

.include "../../mk/bsd.pkg.mk"
