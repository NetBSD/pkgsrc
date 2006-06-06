# $NetBSD: Makefile,v 1.5 2006/06/06 16:54:47 minskim Exp $
#

DISTNAME=	NeTraMet44
PKGNAME=	netramet-4.4.20
CATEGORIES=	security net
MASTER_SITES=	http://foobar.cit.buffalo.edu/nms/NeTraMet/

MAINTAINER=	burgess@neonramp.com
COMMENT=	NEtwork TRaffic METer

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--without-x
MAKE_ENV+=	PCAP_LIB=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libpcap}/lib

.include "../../net/libpcap/buildlink3.mk"

post-patch:
	for i in `${FIND} ${WRKSRC} -name Makefile.in -print`; do	\
		${SED} "s,CFLAGS=,CFLAGS+=,g" $$i > $$i.done;		\
	${MV} $$i.done $$i;						\
	done

.include "../../mk/bsd.pkg.mk"
