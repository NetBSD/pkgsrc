# $NetBSD: Makefile,v 1.9 1998/06/22 11:19:40 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/01/28 08:11:23 asami Exp 
#

DISTNAME=          gdbm-1.7.3
CATEGORIES=        databases
MASTER_SITES=      ${MASTER_SITE_GNU}

MAINTAINER=        packages@netbsd.org

GNU_CONFIGURE=     yes
MAKE_FLAGS=        CFLAGS="${CFLAGS}" LDFLAGS=-s
INFO_FILES=	   gdbm.info

post-build:
	cd ${WRKSRC} ; ${RM} gdbm.info ; make gdbm.info

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
