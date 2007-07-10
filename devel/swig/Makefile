# $NetBSD: Makefile,v 1.23 2007/07/10 19:51:22 heinz Exp $

DISTNAME=	swig-1.3.31
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swig/}

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		swig-build-[0-9]*

CONFIGURE_ARGS+=	--with-swiglibdir=${PREFIX}/share/swig/1.3
BUILD_TARGET=		swig

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

INSTALLATION_DIRS+=	share/doc/swig share/examples/swig

CHECK_INTERPRETER_SKIP+=	share/examples/swig/*

post-install:
	cd ${WRKSRC:Q}/Doc/Manual && \
	${INSTALL_DATA} SWIGDocumentation.html SWIGDocumentation.pdf	\
		*.png ${DESTDIR:Q}${PREFIX:Q}/share/doc/swig
	cd ${WRKSRC:Q}/Examples &&					\
	${PAX} -wr							\
		-s ',.*CVS.*,,'						\
		-s ',.*Makefile\.in$$,,'				\
		-s ',^test-suite.*,,'					\
		. ${DESTDIR:Q}${PREFIX:Q}/share/examples/swig

.include "../../mk/bsd.pkg.mk"
