# $NetBSD: Makefile,v 1.16 2000/12/30 16:54:06 itojun Exp $
# FreeBSD Id: Makefile,v 1.10 1997/08/27 19:31:37 jmacd Exp
#

DISTNAME=		scheme48-0.53
CATEGORIES=		lang
MASTER_SITES=		http://www.neci.nj.nec.com/homepages/kelsey/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.neci.nj.nec.com/homepages/kelsey/

NOT_FOR_PLATFORM=	*-*-alpha	# *severe* problems.  Bus error, alignment

GNU_CONFIGURE=  	yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
ALL_TARGET=		enough

.include "../../mk/bsd.pkg.mk"
