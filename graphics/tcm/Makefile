# $NetBSD: Makefile,v 1.21 2004/10/03 00:14:58 tv Exp $

DISTNAME=		tcm-2.01.src
PKGNAME=		tcm-2.01
PKGREVISION=		2
CATEGORIES=		graphics devel
MASTER_SITES=		ftp://ftp.cs.utwente.nl/pub/tcm/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://wwwhome.cs.utwente.nl/~tcm/index.html
COMMENT=		TCM - Toolkit for Conceptual Modeling

WRKSRC=			${WRKDIR}/tcm-2.01/src
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_X11BASE=		YES

# These two variables denote where the installed location of the libraries
# are located.
#
MAKE_ENV+=		XWIN_HOME=${X11BASE}
MAKE_ENV+=		MOTIF_HOME=${MOTIFBASE}

TCM_SRC=		${WRKDIR}/tcm-2.01
MAKE_ENV+=		TCM_HOME=${TCM_SRC}

CPPFLAGS+=		-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\\\"\"
CONF_FILES=		${PREFIX}/share/examples/tcm/tcm.conf \
			${PKG_SYSCONFDIR}/tcm.conf

ALL_TARGET=		depend all

post-extract:
	${RM} -f ${TCM_SRC}/lib/COPYING ${TCM_SRC}/lib/CHANGELOG

do-configure:
	${RM} -f ${WRKSRC}/Config.tmpl
	${LN} -fs ${WRKSRC}/Config.tmpl_netbsd ${WRKSRC}/Config.tmpl
	${RM} -f ${WRKSRC}/Makefile
	${LN} -fs ${WRKSRC}/Makefile.gcc ${WRKSRC}/Makefile
	${MV} -f ${WRKSRC}/gl/system.c ${WRKSRC}/gl/system.c.dist
	${SED}	-e "s|@PREFIX@|${PREFIX}|g"				\
		-e "s|@X11BASE@|${X11BASE}|g"				\
		-e "s|@LOCALBASE@|${LOCALBASE}|g"			\
	${WRKSRC}/gl/system.c.dist > ${WRKSRC}/gl/system.c
	for f in `${FIND} ${WRKSRC} -name \*.c -print`; do		\
		${MV} -f $$f $$f`${ECHO} c`;				\
	done
	${MV} -f ${WRKSRC}/gl/text2ps.cc ${WRKSRC}/gl/text2ps.c

do-install:
	cd ${TCM_SRC}/bin && ${INSTALL_PROGRAM} tcm tcmd tcmt text2ps 	\
		${PREFIX}/bin/
	for f in tatd tcpd tcrd tdfd tdpd tefd terd tesd tfrt tgd	\
	tgtt tpsd trpg tsnd tssd tstd tucd; do				\
	${LN} -fs ${PREFIX}/bin/tcmd ${PREFIX}/bin/$$f;			\
	done
	for f in tfet tgt ttdt ttut; do					\
	${LN} -fs ${PREFIX}/bin/tcmt ${PREFIX}/bin/$$f;			\
	done
	${INSTALL_SCRIPT} ${TCM_SRC}/bin/psf ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tcm
	${INSTALL_DATA} ${TCM_SRC}/lib/tcm.conf ${PREFIX}/share/examples/tcm
	${INSTALL_DATA} ${TCM_SRC}/lib/TCM ${PREFIX}/lib/X11/app-defaults/
	${INSTALL_DATA} ${TCM_SRC}/man/man1/*.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/tcm
	${INSTALL_DATA} ${TCM_SRC}/lib/colorrgb.txt ${PREFIX}/share/tcm
	${INSTALL_DATA} ${TCM_SRC}/lib/banner.ps ${PREFIX}/share/tcm
	${INSTALL_DATA_DIR} ${PREFIX}/share/tcm/help
	cd ${TCM_SRC} && ${INSTALL_DATA} COPYING CHANGELOG lib/help/* 	\
		${PREFIX}/share/tcm/help/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcm
	cd ${TCM_SRC} && ${INSTALL_DATA} README COPYING CHANGELOG 	\
		${PREFIX}/share/doc/tcm/
	${INSTALL_DATA} ${TCM_SRC}/doc/*.ps.gz ${PREFIX}/share/doc/tcm/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/tcm
	${INSTALL_DATA} ${TCM_SRC}/doc/*.html ${PREFIX}/share/doc/html/tcm/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/tcm/developersguide
	${INSTALL_DATA} ${TCM_SRC}/doc/developersguide/* 		\
		${PREFIX}/share/doc/html/tcm/developersguide/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/tcm/sourcecode
	${INSTALL_DATA} ${TCM_SRC}/doc/sourcecode/* 			\
		${PREFIX}/share/doc/html/tcm/sourcecode/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/tcm/specifications
	${INSTALL_DATA} ${TCM_SRC}/doc/specifications/* 		\
		${PREFIX}/share/doc/html/tcm/specifications/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/tcm/usersguide
	${INSTALL_DATA} ${TCM_SRC}/doc/usersguide/* 			\
		${PREFIX}/share/doc/html/tcm/usersguide/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/tcm/wishlist
	${INSTALL_DATA} ${TCM_SRC}/doc/wishlist/* 			\
		${PREFIX}/share/doc/html/tcm/wishlist/

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if defined(MOTIF_TYPE) && (${MOTIF_TYPE} == "lesstif")
CPPFLAGS+=	-DLESSTIF
.endif
