# $NetBSD: Makefile,v 1.1.1.1 2001/02/24 01:29:53 jtb Exp $

DISTNAME=		tcm-2.01.src
PKGNAME=		tcm-2.01
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.cs.utwente.nl/pub/tcm/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://wwwhome.cs.utwente.nl/~tcm/index.html
COMMENT=		TCM - Toolkit for Conceptual Modeling

WRKSRC=			${WRKDIR}/tcm-2.01/src

HAS_CONFIGURE=		#defined
CONFIGURE_SCRIPT=	${SCRIPTDIR}/configure
USE_X11=		#defined
USE_X11BASE=		#defined
USE_MOTIF=		#defined
MAKE_ENV+=		XWIN_HOME="${X11BASE}"
MAKE_ENV+=		MOTIF_HOME="${MOTIFBASE}"
TCM_SRC=		${WRKDIR}/tcm-2.01
MAKE_ENV+=		TCM_HOME=${TCM_SRC}
ALL_TARGET=		depend all

post-extract:
	${RM} -f ${TCM_SRC}/lib/COPYING ${TCM_SRC}/lib/CHANGELOG

do-configure:
	${SH} ${SCRIPTDIR}/configure

do-install:
	@for f in tcm tcmd tcmt text2ps; do				\
	i="${INSTALL_PROGRAM} ${TCM_SRC}/bin/$$f			\
	${PREFIX}/bin/";						\
	${ECHO} $$i; $$i;						\
	done
	@for f in tatd tcpd tcrd tdfd tdpd tefd terd tesd tfrt tgd	\
	tgtt tpsd trpg tsnd tssd tstd tucd; do				\
	${LN} -fs ${PREFIX}/bin/tcmd ${PREFIX}/bin/$$f;			\
	done
	@for f in tfet tgt ttdt ttut; do				\
	${LN} -fs ${PREFIX}/bin/tcmt ${PREFIX}/bin/$$f;			\
	done
	${INSTALL_SCRIPT} ${TCM_SRC}/bin/psf ${PREFIX}/bin
	${INSTALL_DATA} ${TCM_SRC}/lib/tcm.conf ${PREFIX}/etc

	${INSTALL_DATA} ${TCM_SRC}/lib/TCM				\
	${PREFIX}/lib/X11/app-defaults
	@for f in ${TCM_SRC}/man/man1/*.1; do				\
	i="${INSTALL_MAN} $$f ${PREFIX}/man/man1/";			\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/tcm
	${INSTALL_DATA} ${TCM_SRC}/lib/colorrgb.txt ${PREFIX}/share/tcm
	${INSTALL_DATA} ${TCM_SRC}/lib/banner.ps ${PREFIX}/share/tcm
	${INSTALL_DATA_DIR} ${PREFIX}/share/tcm/help
	@for f in ${TCM_SRC}/lib/help/* ${TCM_SRC}/CHANGELOG 		\
	${TCM_SRC}/COPYING; do					   	\
	i="${INSTALL_DATA} $$f ${PREFIX}/share/tcm/help/";		\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcm
	@for f in README COPYING CHANGELOG; do				\
	i="${INSTALL_DATA} ${TCM_SRC}/$$f				\
	${PREFIX}/share/doc/tcm/";					\
	${ECHO} $$i; $$i;						\
	done
	@for f in ${TCM_SRC}/doc/*.ps.gz; do				\
	i="${INSTALL_DATA} $$f ${PREFIX}/share/doc/tcm/";		\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/tcm
	@for f in ${TCM_SRC}/doc/*.html; do				\
	i="${INSTALL_DATA} $$f ${PREFIX}/share/doc/html/tcm/";		\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/tcm/developersguide
	@for f in ${TCM_SRC}/doc/developersguide/*; do			\
	i="${INSTALL_DATA} $$f						\
	${PREFIX}/share/doc/html/tcm/developersguide/";			\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/tcm/sourcecode
	@for f in ${TCM_SRC}/doc/sourcecode/*; do			\
	i="${INSTALL_DATA} $$f						\
	${PREFIX}/share/doc/html/tcm/sourcecode/";			\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/tcm/specifications
	@for f in ${TCM_SRC}/doc/specifications/*; do			\
	i="${INSTALL_DATA} $$f						\
	${PREFIX}/share/doc/html/tcm/specifications/";			\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/tcm/usersguide
	@for f in ${TCM_SRC}/doc/usersguide/*; do			\
	i="${INSTALL_DATA} $$f						\
	${PREFIX}/share/doc/html/tcm/usersguide/";			\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/tcm/wishlist
	@for f in ${TCM_SRC}/doc/wishlist/*; do			\
	i="${INSTALL_DATA} $$f						\
	${PREFIX}/share/doc/html/tcm/wishlist/";			\
	${ECHO} $$i; $$i;						\
	done

.include "../../mk/bsd.pkg.mk"
