# $NetBSD: Makefile,v 1.2 2001/05/02 10:14:02 zuntum Exp $
#

DISTNAME=	NeTraMet44b8
PKGNAME=	netramet-4.4.8
CATEGORIES=	security net
MASTER_SITES=	http://foobar.cit.buffalo.edu/nms/NeTraMet/beta-versions/

MAINTAINER=	burgess@neonramp.com
HOMEPAGE=	http://www.auckland.ac.nz/net/Accounting/
COMMENT=	NEtwork TRaffic METer

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--without-x

post-patch:
	for i in `${FIND} ${WRKSRC} -name Makefile.in`; do			\
		${SED} "s,CFLAGS=,CFLAGS+=,g" $$i > $$i.done;			\
	${MV} $$i.done $$i;							\
	done

.include "../../mk/bsd.pkg.mk"
