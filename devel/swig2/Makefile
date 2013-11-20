# $NetBSD: Makefile,v 1.6 2013/11/20 20:04:37 adam Exp $

DISTNAME=	swig-2.0.10
PKGNAME=	${DISTNAME:S/swig-/swig2-/}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swig/}

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator (version 2)
LICENSE=	2-clause-bsd

CONFLICTS=		swig-build-[0-9]*

# This package mostly can replace swig (1), but it is likely not
# entirely compatible (per upstream).  So the plan is to keep
# devel/swig and devel/swig2 both for a while.  This package is
# configured to install swig as "swig2", so that swig and swig2 can be
# installed in parallel.  The downside of that is that depending
# packages must check for and use swig2.  Thus, the decision about
# naming is open to being revisited.

## Notes about pkgsrc-wide transition to swig2:

# 2012-10: gnuradio is said to work with swig2 (private communication
# by gdt@ with a GNU Radio developer).  However, it doesn't find 'swig2'.
# Solution: Use --program-suffix=2.0, not --program-suffix=2
# FindSWIG, installed by cmake, looks for executable named swig2.0, then swig
# bin/swig2.0 is the standard used by other OS's
# http://packages.debian.org/sid/i386/swig2.0/filelist
# http://svnweb.freebsd.org/ports/head/devel/swig20/pkg-plist?revision=306553&view=markup

# Keep the path from changing due to minor version bumps.
CONFIGURE_ARGS+=	--with-swiglibdir=${PREFIX}/share/swig/2.0 \
			--program-suffix=2.0
BUILD_TARGET=		swig

USE_TOOLS+=		gmake pax
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

INSTALLATION_DIRS+=	share/doc/swig/2.0 share/examples/swig/2.0

CHECK_INTERPRETER_SKIP+=	share/examples/swig/*

# configure fails to generate this on NetBSD
LDFLAGS+=	-lpcre

TEST_TARGET=	check
# Tests require lots of other dependencies.  There should be a better
# way to encode this, but for now they are commented out -gdt.
#.include "../../lang/python/extension.mk"
#.include "../../lang/php53/buildlink3.mk"
#.include "../../devel/boost-libs/buildlink3.mk"

post-install:
	cd ${WRKSRC}/Doc/Manual && \
	${INSTALL_DATA} SWIGDocumentation.html SWIGDocumentation.pdf	\
		*.png ${DESTDIR}${PREFIX}/share/doc/swig/2.0
	cd ${WRKSRC}/Examples &&					\
	pax -wr								\
		-s ',.*CVS.*,,'						\
		-s ',.*Makefile\.in$$,,'				\
		-s ',^test-suite.*,,'					\
		. ${DESTDIR}${PREFIX}/share/examples/swig/2.0

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
