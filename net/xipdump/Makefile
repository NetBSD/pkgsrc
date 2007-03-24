# $NetBSD: Makefile,v 1.27 2007/03/24 19:21:31 joerg Exp $
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

INSTALLATION_DIRS=	bin lib/X11/app-defaults ${PKGMANDIR}/man8

LIBNET_CFLAGS_CMD= ${BUILDLINK_PREFIX.libnet10}/bin/libnet10-config --defines

post-build:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${WRKSRC}/data; ${FIND} pkc pkt ! -type d -print | \
		${SED} -e 's|^|share/xipdump/|' >> ${PLIST_SRC})
	@${ECHO} "@dirrm share/xipdump/pkt" >> ${PLIST_SRC}
	@${ECHO} "@dirrm share/xipdump/pkc" >> ${PLIST_SRC}
	@${ECHO} "@dirrm share/xipdump" >> ${PLIST_SRC}

.include "../../devel/libnet10/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
