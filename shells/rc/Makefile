# $NetBSD: Makefile,v 1.14 2003/01/28 22:04:12 jlam Exp $
# FreeBSD Id: Makefile,v 1.3 1996/11/12 02:19:38 obrien Exp
#

DISTNAME=       rc-1.6
CATEGORIES=	shells plan9
MASTER_SITES=   http://www.star.le.ac.uk/%7Etjg/rc/release/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.star.le.ac.uk/%7Etjg/rc/
COMMENT=	Unix incarnation of the plan9 shell

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-history

USE_PKGINSTALL=	yes
PKG_SHELL=	${PREFIX}/bin/rc

.include "../../mk/bsd.pkg.mk"
