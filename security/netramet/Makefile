# $NetBSD: Makefile,v 1.4 2004/01/27 00:53:10 heinz Exp $
#

DISTNAME=	NeTraMet44
PKGNAME=	netramet-4.4.20
CATEGORIES=	security net
MASTER_SITES=	http://foobar.cit.buffalo.edu/nms/NeTraMet/

MAINTAINER=	burgess@neonramp.com
COMMENT=	NEtwork TRaffic METer

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--without-x

post-patch:
	for i in `${FIND} ${WRKSRC} -name Makefile.in -print`; do	\
		${SED} "s,CFLAGS=,CFLAGS+=,g" $$i > $$i.done;		\
	${MV} $$i.done $$i;						\
	done

.include "../../mk/bsd.pkg.mk"
