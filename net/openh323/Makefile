# $NetBSD: Makefile,v 1.16 2003/05/05 19:05:17 jmmv Exp $
#

DISTNAME=	openh323_1.10.4
PKGNAME=	openh323-1.10.4
PKGREVISION=	1
WRKSRC=		${WRKDIR}/openh323
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.us1.openh323.org/bin/ \
		http://www.us2.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.at.openh323.org/bin/ \
		http://www.cz.openh323.org/bin/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.openh323.org/
COMMENT=	Open H.323 library

MAKE_ENV+=	PWLIBDIR=${PREFIX} OPENH323DIR=${WRKSRC}

USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
ALL_TARGET=	opt

post-patch:
		-${MKDIR} ${WRKSRC}/lib; cd ${WRKSRC}/lib; ${LN} -s ${PREFIX}/lib/libpt.la
		cd ${WRKSRC}/include; ${LN} -s . openh323
		${_PKG_SILENT}cd ${WRKSRC};			\
		for f in openh323u.mak; do			\
			${SED} ${FILES_SUBST_SED} $$f > $$f.sed;\
			${MV} -f $$f.sed $$f;			\
		done

# override the openh323 install - it uses cp -d, and isn't libtool-aware
do-install:
		cd ${WRKSRC}/src; ${MAKE_ENV} ${GMAKE} install
		${INSTALL_DATA_DIR} ${PREFIX}/include/openh323
		cd ${WRKSRC}/include;				\
                 for f in \*.h ; \
			do ${INSTALL_DATA} $$f ${PREFIX}/include/openh323; done
		cd ${WRKSRC}/samples/simple; ${MAKE_ENV} ${GMAKE} install
		-${INSTALL_DATA_DIR} ${PREFIX}/share/openh323
		cd ${WRKSRC}; ${INSTALL_DATA} openh323u.mak ${PREFIX}/share/openh323

.include "../../devel/pwlib/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
