# $NetBSD: Makefile,v 1.14 1999/02/20 22:48:33 hubertf Exp $
# FreeBSD Id: Makefile,v 1.10 1997/08/27 19:31:37 jmacd Exp
#

DISTNAME=	scheme48-0.52
CATEGORIES=	lang
MASTER_SITES=	http://www.neci.nj.nec.com/homepages/kelsey/
EXTRACT_SUFX=	.tgz

MAINTAINER= 	packages@netbsd.org
HOMEPAGE=	http://www.neci.nj.nec.com/homepages/kelsey/

NOT_FOR_ARCHS=	alpha	# *severe* problems.  Bus error, alignment

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+= --prefix=${PREFIX}
ALL_TARGET = 	enough

.include "../../mk/bsd.pkg.mk"
