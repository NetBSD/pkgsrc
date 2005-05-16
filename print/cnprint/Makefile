# $NetBSD: Makefile,v 1.5 2005/05/16 01:15:32 jlam Exp $

DISTNAME=		#
PKGNAME=		cnprint-3.30b
CATEGORIES=		print
MASTER_SITES=		http://nba184.med.uth.tmc.edu:3006/~cai/software/cnp/ \
			http://nba184.med.uth.tmc.edu:3006/~cai/software/cnp/metrics/ \
			http://nba184.med.uth.tmc.edu:3006/~cai/software/cnp/fonts/ \
			ftp://ftp.csc.cuhk.edu.hk/pub/chinese/ifcss/software/fonts/misc/
EXTRACT_SUFX=		#empty
DISTFILES+=		cnprint330b.c \
			cnprint330b.readme \
			ttfb330b.c \
			cnprint330b.hlp \
			cnprint33.cmd \
			helvet.dat  \
			mssong.ttf.gz mssong.htf \
			mshei.ttf.gz mshei.htf \
			cc48s.hbf cc48.sym.gz \
			cc48s.1.gz \
			cc48s.2.gz \
			hbf.tar.gz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.neurophys.wisc.edu/~cai/software/index.html
COMMENT=		Print & convert CJK style text to PostScript

DIST_SUBDIR=		${PKGNAME}
PKGSRC_USE_TOOLS+=	gtar gunzip

do-extract:
	${MKDIR} ${WRKSRC}
.for i in ${DISTFILES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${i} ${WRKSRC}
.endfor
	cd ${WRKSRC} ; \
	${GTAR} plzvxf hbf.tar.gz ; ${MV} hbf/* . ; \
	${RM} -fr hbf ; \
	${GUNZIP_CMD} *.gz || ${TRUE}

do-build:
	cd ${WRKSRC} ; \
	${CC} cnprint330b.c ttfb330b.c -o cnprint -DPREFIX=\"${PREFIX}\" ; \
	${SED} \
		-e 's/\(DEFAULT_JIS_FONT\):.*$$/\1: kanji48.hbf/' \
		>cnprint.cmd <cnprint33.cmd

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/cnprint.cmd ${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.sym ${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.htf ${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.hbf ${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.bin ${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${PREFIX}/share/cnprint
	${INSTALL_PROGRAM} ${WRKSRC}/cnprint ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
