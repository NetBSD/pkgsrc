# $NetBSD: Makefile,v 1.8 1998/06/10 08:02:08 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/01/28 08:11:23 asami Exp 
#

DISTNAME=          gdbm-1.7.3
CATEGORIES=        databases
MASTER_SITES=      ${MASTER_SITE_GNU}

MAINTAINER=        packages@netbsd.org

GNU_CONFIGURE=     yes
MAKE_FLAGS=        CFLAGS="${CFLAGS}" LDFLAGS=-s
MAN3=		   gdbm.3
INFO_FILES=	   gdbm.info

post-build:
	cd ${WRKSRC} ; ${RM} gdbm.info ; make gdbm.info

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
