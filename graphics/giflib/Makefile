# $NetBSD: Makefile,v 1.32 2001/09/27 23:18:11 jlam Exp $
#

DISTNAME=		giflib-4.1.0
CATEGORIES=		graphics
MASTER_SITES=		ftp://prtr-13.ucsc.edu/pub/libungif/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://prtr-13.ucsc.edu/~badger/software/libungif/index.shtml
COMMENT=		Tools and library routines for working with GIF images

CONFLICTS=		libungif-[0-9]*

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--without-x

USE_BUILDLINK_ONLY=	# defined

DOCDIR=			${PREFIX}/share/doc/giflib
HTMLDIR=		${PREFIX}/share/doc/html/giflib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CC="${CC} -I${LOCALBASE}/include"
.endif

post-patch:
	${RM} ${WRKSRC}/doc/gif2x11.html

# We patch configure.in, so touch the Makefile.in files to prevent automake
# from regenerating them.
#
pre-build:
	${TOUCH} ${WRKSRC}/aclocal.m4
	${FIND} ${WRKSRC} -name "Makefile.in" -print | ${XARGS} ${TOUCH}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING PATENT_PROBLEMS ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt *.png ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
