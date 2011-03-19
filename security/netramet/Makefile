# $NetBSD: Makefile,v 1.8 2011/03/19 09:36:47 obache Exp $
#

DISTNAME=	NeTraMet44
PKGNAME=	netramet-4.4.20
CATEGORIES=	security net
MASTER_SITES=	# http://foobar.cit.buffalo.edu/nms/NeTraMet/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	NEtwork TRaffic METer
#LICENSE=	GNU EMACS GENERAL PUBLIC LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--without-x
MAKE_ENV+=	PCAP_LIB=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libpcap}/lib
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../net/libpcap/buildlink3.mk"

post-patch:
	for i in `${FIND} ${WRKSRC} -name Makefile.in -print`; do	\
		${SED} "s,CFLAGS=,CFLAGS+=,g" $$i > $$i.done;		\
	${MV} $$i.done $$i;						\
	done

.include "../../mk/bsd.pkg.mk"
