# $NetBSD: Makefile,v 1.35 2013/08/02 13:24:10 jaapb Exp $

DISTNAME=	swig-1.3.36
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swig/}

#
# 1.3.37 has a bug where .py files are written to the directory of the
# .i file instead of where the output is supposed to go, and this
# breaks gnuradio.  Please try to contact gdt@netbsd.org before
# updating to 1.3.37.  See message on discuss-gnuradio:
# Message-Id: <FA0E4567-C660-4C30-B604-2FA000330874@alum.mit.edu>
# As of 2012-10, gnuradio is known to work with swig 2.
#
# x11/ruby-wxruby-2.0.1 requires 1.3.32 for Ruby 1.8 and 1.3.37 for
# Ruby 1.9.  And SWIG 1.3.39 introduced some incompatibility with
# wxRuby, sigh.
#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator (version 1)
LICENSE=	2-clause-bsd

CONFLICTS=		swig-build-[0-9]*

CONFIGURE_ARGS+=	--with-swiglibdir=${PREFIX}/share/swig/1.3
BUILD_TARGET=		swig

USE_TOOLS+=		gmake pax perl
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

INSTALLATION_DIRS+=	share/doc/swig share/examples/swig

CHECK_INTERPRETER_SKIP+=	share/examples/swig/*

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
