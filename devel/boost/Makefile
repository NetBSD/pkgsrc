# $NetBSD: Makefile,v 1.1.1.1 2000/05/09 20:44:04 jlam Exp $

DISTNAME=		boost_all
PKGNAME=		boost-1.14.1
CATEGORIES=		devel
MASTER_SITES=		http://www.boost.org/
EXTRACT_SUFX=		.zip

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.boost.org/

DIST_SUBDIR=		${PKGNAME}
EXTRACT_CMD=		${LOCALBASE}/bin/unzip -uLa ${DOWNLOADED_DISTFILE}
NO_WRKSUBDIR=		# defined

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

BOOSTDIR=		${PREFIX}/include/boost
HTMLDOCDIR=		${PREFIX}/share/doc/html/boost

do-install:
	${INSTALL_DATA_DIR} ${BOOSTDIR}
	${INSTALL_DATA_DIR} ${BOOSTDIR}/detail
	cd ${WRKSRC}/boost; for file in *.h *.hpp */*.hpp; do \
		${INSTALL_DATA} $${file} ${BOOSTDIR}/$${file}; \
	done

	${INSTALL_DATA_DIR} ${HTMLDOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/libs
.for DIR in array compose dir_it integer min_rand pri_queue rational \
	    smart_ptr timer utility
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/libs/${DIR}
.endfor
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/people

	cd ${WRKSRC}; ${INSTALL_DATA} *.htm ${HTMLDOCDIR}
	cd ${WRKSRC}/libs; for file in */*.cpp */*.gif */*.htm */*.jpg; do \
		${INSTALL_DATA} $${file} ${HTMLDOCDIR}/libs/$${file}; \
	done
	cd ${WRKSRC}/people; ${INSTALL_DATA} * ${HTMLDOCDIR}/people

.include "../../mk/bsd.pkg.mk"
