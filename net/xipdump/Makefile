# $NetBSD: Makefile,v 1.1.1.1 1999/11/15 02:29:51 sakamoto Exp $
#

DISTNAME=	xipdump-1.5.1
CATEGORIES=	net
MASTER_SITES=	http://www.epita.fr/~lse/xipdump/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.epita.fr/~lse/xipdump/

DEPENDS+=	libnet-1.0:../../devel/libnet

LIBNET_CONFIG=	${LOCALBASE}/bin/libnet-config

PLIST_SRC=	${WRKDIR}/PLIST

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="`${LIBNET_CONFIG} --cflags` `${LIBNET_CONFIG} --defines`" \
		LIBS="`${LIBNET_CONFIG} --libs`"

post-build:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${WRKSRC}/data; find pkc pkt ! -type d | \
		${SED} -e 's|^|share/xipdump/|' >> ${PLIST_SRC})
	@${ECHO} "@dirrm share/xipdump/pkt" >> ${PLIST_SRC}
	@${ECHO} "@dirrm share/xipdump/pkc" >> ${PLIST_SRC}
	@${ECHO} "@dirrm share/xipdump" >> ${PLIST_SRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/Xipdump.ad ${PREFIX}/lib/X11/app-defaults

.include "../../mk/bsd.pkg.mk"
