# $NetBSD: Makefile,v 1.10 1998/08/20 15:17:08 tsarna Exp $
# FreeBSD Id: Makefile,v 1.10 1997/08/27 19:31:37 jmacd Exp
#

DISTNAME=	scheme48-0.51
CATEGORIES=	lang
MASTER_SITES=	http://www.neci.nj.nec.com/homepages/kelsey/
EXTRACT_SUFX=	.tgz

MAINTAINER= 	packages@netbsd.org
HOMEPAGE=	http://www.neci.nj.nec.com/homepages/kelsey/

CONFLICTS=	scheme48-0.46

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+= --prefix=${PREFIX}
ALL_TARGET = 	enough

.include "../../mk/bsd.pkg.mk"
