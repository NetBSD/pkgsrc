# $NetBSD: Makefile,v 1.3 2000/12/21 10:21:32 skrll Exp $
#

DISTNAME=	icu-1.6
CATEGORIES=	textproc
MASTER_SITES=	http://oss.software.ibm.com/icu/download/1.6/
EXTRACT_SUFX=	.tgz

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://oss.software.ibm.com/icu

WRKSRC=		${WRKDIR}/icu/source
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS+= --disable-threads

CPPFLAGS+=	-I${LOCALBASE}/include

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

post-extract:
	${CP} ${FILESDIR}/mh-netbsd ${WRKSRC}/config

pre-configure:
	${CHMOD} u+rx ${WRKSRC}/configure

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/icu
	${INSTALL_DATA} ${WRKDIR}/icu/docs/* ${PREFIX}/share/doc/html/icu

test: build
	cd ${WRKSRC} && ${MAKE_PROGRAM} check

.include "../../mk/bsd.pkg.mk"
