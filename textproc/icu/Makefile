# $NetBSD: Makefile,v 1.4 2000/12/21 18:14:18 skrll Exp $
#

DISTNAME=	icu-1.7
CATEGORIES=	textproc
MASTER_SITES=	http://oss.software.ibm.com/icu/download/1.7/
EXTRACT_SUFX=	.tgz

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://oss.software.ibm.com/icu

WRKSRC=		${WRKDIR}/icu/source
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS+= --disable-threads

CPPFLAGS+=	-I${LOCALBASE}/include

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

pre-configure:
	${CHMOD} u+rx ${WRKSRC}/configure

test: build
	cd ${WRKSRC} && ${MAKE_PROGRAM} check

.include "../../mk/bsd.pkg.mk"
