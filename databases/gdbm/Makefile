# $NetBSD: Makefile,v 1.13 1999/03/08 10:53:56 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/01/28 08:11:23 asami Exp 
#

DISTNAME=	gdbm-1.7.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gdbm/gdbm.html

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

INFO_FILES=	gdbm.info

post-build:
	cd ${WRKSRC} ; ${RM} gdbm.info ; ${MAKE} gdbm.info

.include "../../mk/bsd.pkg.mk"
