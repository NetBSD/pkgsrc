# $NetBSD: Makefile,v 1.11 2003/03/22 04:43:17 wiz Exp $
#

DISTNAME=	libnet-1.0.1b
PKGREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.packetfactory.net/libnet/
COMMENT=	C library for portable packet creation and injection

USE_BUILDLINK2= # defined

USE_LIBTOOL=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	LIBNET_CONFIG_CFLAGS="-I${PREFIX}/include" \
		LIBNET_CONFIG_LIBS="${LDFLAGS}"

WRKSRC=		${WRKDIR}/${DISTNAME:C/l/L/}
PLIST_SRC=	${WRKDIR}/PLIST
DOCDIR=		share/doc/libnet

post-extract:
	${CHMOD} -R a+r ${WRKSRC}/doc

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libnet
	@(cd ${WRKSRC}/doc/html; ${GTAR} cf - *.html *.gif */*.c | \
		(cd ${PREFIX}/${DOCDIR};${GTAR} xf -))
	@${LN} -s ${PREFIX}/share/doc/libnet/examples \
		${PREFIX}/share/examples/libnet
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${PREFIX};	\
	  ${FIND} ${DOCDIR} -type f >> ${PLIST_SRC}; \
	  ${FIND} ${DOCDIR} -type d| ${SED} -e 's|^|@dirrm |' | ${SORT} -r \
		>> ${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
