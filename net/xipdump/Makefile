# $NetBSD: Makefile,v 1.14 2005/01/28 23:35:59 adrianp Exp $
#

DISTNAME=	xipdump-1.5.4
CATEGORIES=	net
MASTER_SITES=	http://www.lse.epita.fr/devel/xipdump/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sakamoto@NetBSD.org
#HOMEPAGE=	http://www.epita.fr/~lse/xipdump/	
COMMENT=	Displays IP packets using X Window System

USE_BUILDLINK3=	YES

BUILDLINK_DEPENDS.libnet+=	libnet<=1.0.1b

LIBNET_CONFIG=	${LOCALBASE}/bin/libnet-config

PLIST_SRC=	${WRKDIR}/PLIST

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${PREFIX}/include `${LIBNET_CONFIG} --defines`
LIBS=		-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lnet

post-build:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${WRKSRC}/data; ${FIND} pkc pkt ! -type d -print | \
		${SED} -e 's|^|share/xipdump/|' >> ${PLIST_SRC})
	@${ECHO} "@dirrm share/xipdump/pkt" >> ${PLIST_SRC}
	@${ECHO} "@dirrm share/xipdump/pkc" >> ${PLIST_SRC}
	@${ECHO} "@dirrm share/xipdump" >> ${PLIST_SRC}

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
