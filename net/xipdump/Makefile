# $NetBSD: Makefile,v 1.25 2007/02/18 18:55:17 adrianp Exp $
#

DISTNAME=	xipdump-1.5.4
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.lse.epita.fr/twiki/pub/Projects/XipDump/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lse.epita.fr/twiki/bin/view/Projects/XipDump
COMMENT=	Displays IP packets using X Window System

PLIST_SRC=	${WRKDIR}/PLIST

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${PREFIX}/include ${LIBNET_CFLAGS_CMD:sh}
LIBS+=		-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lnet

LIBNET_CFLAGS_CMD= ${BUILDLINK_PREFIX.libnet10}/bin/libnet10-config --defines

post-build:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${WRKSRC}/data; ${FIND} pkc pkt ! -type d -print | \
		${SED} -e 's|^|share/xipdump/|' >> ${PLIST_SRC})
	@${ECHO} "@dirrm share/xipdump/pkt" >> ${PLIST_SRC}
	@${ECHO} "@dirrm share/xipdump/pkc" >> ${PLIST_SRC}
	@${ECHO} "@dirrm share/xipdump" >> ${PLIST_SRC}

.include "../../devel/libnet10/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
