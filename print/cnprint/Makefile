# $NetBSD: Makefile,v 1.17 2017/01/19 18:52:22 agc Exp $

DISTNAME=		#
PKGNAME=		cnprint-3.30b
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		http://www.ywpw.com/cai/software/cnp/
MASTER_SITES+=		http://www.ywpw.com/cai/software/cnp/fonts/
MASTER_SITES+=		http://www.ywpw.com/cai/software/cnp/metrics/
MASTER_SITES+=		ftp://ftp.csc.cuhk.edu.hk/pub/chinese/ifcss/software/fonts/misc/
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

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ywpw.com/cai/software/
COMMENT=		Print & convert CJK style text to PostScript

DIST_SUBDIR=		${PKGNAME_NOREV}
USE_TOOLS+=		tar gunzip gzcat
INSTALLATION_DIRS=	bin share/cnprint

do-extract:
	${MKDIR} ${WRKSRC}
.for i in ${DISTFILES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${i} ${WRKSRC}
.endfor
	cd ${WRKSRC} && (${GZCAT} hbf.tar.gz || ${TRUE}) | ${TAR} xf -
	${MV} ${WRKSRC}/hbf/* ${WRKSRC}/
	${RM} -fr ${WRKSRC}/hbf
	${GUNZIP_CMD} ${WRKSRC}/*.gz || ${TRUE}

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} cnprint330b.c ttfb330b.c -o cnprint -DPREFIX=\"${PREFIX}\" && \
	${SED} \
		-e 's/\(DEFAULT_JIS_FONT\):.*$$/\1: kanji48.hbf/' \
		>cnprint.cmd <cnprint33.cmd

do-install:
	${INSTALL_DATA} ${WRKSRC}/cnprint.cmd ${DESTDIR}${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.sym ${DESTDIR}${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.htf ${DESTDIR}${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.hbf ${DESTDIR}${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.bin ${DESTDIR}${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${PREFIX}/share/cnprint
	${INSTALL_PROGRAM} ${WRKSRC}/cnprint ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
