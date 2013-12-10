# $NetBSD: Makefile,v 1.11 2013/12/10 14:07:44 jperkin Exp $
#

DISTNAME=	NeTraMet44
PKGNAME=	netramet-4.4.20
PKGREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	# http://foobar.cit.buffalo.edu/nms/NeTraMet/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	NEtwork TRaffic METer
#LICENSE=	GNU EMACS GENERAL PUBLIC LICENSE

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--without-x
MAKE_ENV+=	PCAP_LIB=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libpcap}/lib
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../net/libpcap/buildlink3.mk"

CFLAGS.SunOS+=	-Du_int64_t=uint64_t

post-patch:
	for i in `${FIND} ${WRKSRC} -name Makefile.in -print`; do	\
		${SED} "s,CFLAGS=,CFLAGS+=,g" $$i > $$i.done;		\
	${MV} $$i.done $$i;						\
	done

.include "../../mk/bsd.pkg.mk"
