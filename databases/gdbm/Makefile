# $NetBSD: Makefile,v 1.17 2000/06/08 22:28:28 jlam Exp $
# FreeBSD Id: Makefile,v 1.4 1997/01/28 08:11:23 asami Exp 
#

DISTNAME=	gdbm-1.7.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU:=gdbm/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gdbm/gdbm.html

GNU_CONFIGURE=	# defined
USE_LIBTOOL=	# defined

INFO_FILES=	gdbm.info

post-build:
	cd ${WRKSRC} ; ${RM} gdbm.info ; ${MAKE} gdbm.info

.include "../../mk/bsd.pkg.mk"
