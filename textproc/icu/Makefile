# $NetBSD: Makefile,v 1.7 2001/06/11 06:34:52 jlam Exp $
#

DISTNAME=	icu-1.7
CATEGORIES=	textproc
MASTER_SITES=	http://oss.software.ibm.com/icu/download/1.7/
EXTRACT_SUFX=	.tgz

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://oss.software.ibm.com/icu
COMMENT=	Robust and full-featured unicode support

WRKSRC=		${WRKDIR}/icu/source
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

PLIST_INIT=	${PKGDIR}/PLIST
PLIST_SRC=	${WRKSRC}/PLIST

CONFIGURE_ARGS+= --disable-threads

CPPFLAGS+=	-I${LOCALBASE}/include

pre-configure:
	${CHMOD} u+rx ${WRKSRC}/configure

test: build
	cd ${WRKSRC} && ${MAKE_PROGRAM} check

post-install:
	@${CP} ${PLIST_INIT} ${PLIST_SRC}
	@(cd ${PREFIX} && ls lib/icu/1.7/libicudt17[lb].so >> ${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
