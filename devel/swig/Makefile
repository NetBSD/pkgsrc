# $NetBSD: Makefile,v 1.43 2022/06/28 11:33:44 wiz Exp $

DISTNAME=	swig-1.3.38
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swig/}

# x11/ruby-wxruby-2.0.1 requires 1.3.37 for Ruby 1.9.  But SWIG 1.3.39
# introduced some incompatibility with wxRuby, sigh.
#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator (version 1)
LICENSE=	2-clause-bsd

CONFLICTS=		swig-build-[0-9]*

CONFIGURE_ARGS+=	--with-swiglibdir=${PREFIX}/share/swig/1.3
CONFIGURE_ARGS+=	--without-perl5
BUILD_TARGET=		swig

USE_TOOLS+=		gmake pax
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

INSTALLATION_DIRS+=	share/doc/swig share/examples/swig

CHECK_INTERPRETER_SKIP+=	share/examples/swig/*
CHECK_WRKREF_SKIP+=		share/examples/swig/*

post-install:
	cd ${WRKSRC}/Doc/Manual && \
	${INSTALL_DATA} SWIGDocumentation.html SWIGDocumentation.pdf	\
		*.png ${DESTDIR}${PREFIX}/share/doc/swig
	cd ${WRKSRC}/Examples &&					\
	pax -wr								\
		-s ',.*CVS.*,,'						\
		-s ',.*Makefile\.in$$,,'				\
		-s ',^test-suite.*,,'					\
		. ${DESTDIR}${PREFIX}/share/examples/swig

.include "../../mk/bsd.pkg.mk"
