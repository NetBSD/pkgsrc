# $NetBSD: Makefile,v 1.4 2000/08/14 12:07:45 itojun Exp $
#

DISTNAME=	libnet-1.0.1b
CATEGORIES=	devel net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.packetfactory.net/libnet/

USE_PKGLIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBNET_CONFIG_CFLAGS="-I${PREFIX}/include" \
		LIBNET_CONFIG_LIBS="${LDFLAGS}"

WRKSRC=		${WRKDIR}/${DISTNAME:C/l/L/}
PLIST_SRC=	${WRKDIR}/PLIST
DOCDIR=		share/doc/libnet

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libnet
	@(cd ${WRKSRC}/doc/html; ${GTAR} cf - *.html *.gif */*.c | \
		(cd ${PREFIX}/${DOCDIR};${GTAR} xf -))
	@${LN} -s ${PREFIX}/share/doc/libnet/examples \
		${PREFIX}/share/examples/libnet
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${PREFIX};	\
	  ${FIND} ${DOCDIR} -type f >> ${PLIST_SRC}; \
	  ${FIND} ${DOCDIR} -type d| ${SED} -e 's|^|@dirrm |' | sort -r \
		>> ${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
