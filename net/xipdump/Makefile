# $NetBSD: Makefile,v 1.6 2001/02/17 18:19:58 wiz Exp $
#

DISTNAME=	xipdump-1.5.4
CATEGORIES=	net
MASTER_SITES=	http://www.epita.fr/~lse/xipdump/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.epita.fr/~lse/xipdump/
COMMENT=	displays IP packets using X Window System

DEPENDS+=	libnet>=1.0:../../devel/libnet

LIBNET_CONFIG=	${LOCALBASE}/bin/libnet-config

PLIST_SRC=	${WRKDIR}/PLIST

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="`${LIBNET_CONFIG} --cflags` `${LIBNET_CONFIG} --defines`" \
		LIBS="`${LIBNET_CONFIG} --libs`"

post-build:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${WRKSRC}/data; ${FIND} pkc pkt ! -type d | \
		${SED} -e 's|^|share/xipdump/|' >> ${PLIST_SRC})
	@${ECHO} "@dirrm share/xipdump/pkt" >> ${PLIST_SRC}
	@${ECHO} "@dirrm share/xipdump/pkc" >> ${PLIST_SRC}
	@${ECHO} "@dirrm share/xipdump" >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
