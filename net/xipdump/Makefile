# $NetBSD: Makefile,v 1.17 2005/03/19 17:02:32 tv Exp $
#

DISTNAME=	xipdump-1.5.4
CATEGORIES=	net
MASTER_SITES=	http://www.lse.epita.fr/devel/xipdump/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sakamoto@NetBSD.org
#HOMEPAGE=	http://www.epita.fr/~lse/xipdump/
COMMENT=	Displays IP packets using X Window System

USE_BUILDLINK3=	YES

BUILDLINK_DEPENDS.libnet+=	libnet-1.0.*

PLIST_SRC=	${WRKDIR}/PLIST

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${PREFIX}/include ${LIBNET_CFLAGS_CMD:sh}
LIBS=		-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lnet

LIBNET_CFLAGS_CMD= ${BUILDLINK_PREFIX.libnet}/bin/libnet-config --defines

post-build:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${WRKSRC}/data; ${FIND} pkc pkt ! -type d -print | \
		${SED} -e 's|^|share/xipdump/|' >> ${PLIST_SRC})
	@${ECHO} "@dirrm share/xipdump/pkt" >> ${PLIST_SRC}
	@${ECHO} "@dirrm share/xipdump/pkc" >> ${PLIST_SRC}
	@${ECHO} "@dirrm share/xipdump" >> ${PLIST_SRC}

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
