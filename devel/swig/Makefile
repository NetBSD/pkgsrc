# $NetBSD: Makefile,v 1.19 2006/05/21 16:34:19 rillig Exp $

DISTNAME=	swig-1.3.29
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swig/}

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator

CONFLICTS=	swig-build-[0-9]*

CONFIGURE_ARGS+=	--with-swiglibdir=${PREFIX}/share/swig/1.3
BUILD_TARGET=		swig

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

INSTALLATION_DIRS+=	share/doc/swig share/examples/swig

CHECK_INTERPRETER_SKIP+=	share/examples/swig/guile/matrix/matrix.scm

post-install:
	cd ${WRKSRC:Q}/Doc/Manual && \
	${INSTALL_DATA} SWIGDocumentation.html SWIGDocumentation.pdf	\
		*.png ${PREFIX:Q}/share/doc/swig
	cd ${WRKSRC:Q}/Examples &&					\
	${PAX} -wr							\
		-s ',.*CVS.*,,'						\
		-s ',.*Makefile\.in$$,,'				\
		-s ',^test-suite.*,,'					\
		. ${PREFIX:Q}/share/examples/swig

.include "../../mk/bsd.pkg.mk"
