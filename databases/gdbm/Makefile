# $NetBSD: Makefile,v 1.10 1998/07/14 16:21:35 agc Exp $
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

.include "../../mk/bsd.pkg.mk"
