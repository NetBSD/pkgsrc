# $NetBSD: Makefile,v 1.4 1998/04/15 10:38:18 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/01/28 08:11:23 asami Exp 
#

DISTNAME=          gdbm-1.7.3
CATEGORIES=        databases
MASTER_SITES=      ${MASTER_SITE_GNU}

MAINTAINER=        bjn@visi.com

BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo

GNU_CONFIGURE=     yes
MAKE_FLAGS=        CFLAGS="${CFLAGS}" LDFLAGS=-s -f
MAN3=		   gdbm.3

post-build:
	cd ${WRKSRC} ; ${RM} gdbm.info ; make gdbm.info

post-install:
	@install-info ${PREFIX}/info/gdbm.info ${PREFIX}/info/dir

.include "../../mk/bsd.pkg.mk"
