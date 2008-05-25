# $NetBSD: Makefile,v 1.17 2008/05/25 21:42:20 joerg Exp $
#

DISTNAME=		MUMmer3.19
PKGNAME=		mummer-3.19
CATEGORIES=		biology
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mummer/}

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://mummer.sourceforge.net/
COMMENT=		System for aligning whole genome sequences

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_TOOLS+=		csh:run gmake perl:run pax
USE_LANGUAGES=		c c++

MAKE_ENV+=		SH=${SH:Q}
MAKE_ENV+=		PERL=${PERL5:Q}
MAKE_ENV+=		CSH=${TOOLS_PATH.csh:Q}
INSTALLATION_DIRS=	bin share/doc/mummer share/mummer

do-install:
.for p in annotate combineMUMs delta-filter gaps mgaps mummer \
	repeat-match show-aligns show-coords show-snps show-tiling
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${DESTDIR}${PREFIX}/bin
.endfor
.for p in postnuc postpro prenuc prepro
	${INSTALL_PROGRAM} ${WRKSRC}/aux_bin/${p} ${DESTDIR}${PREFIX}/bin
.endfor
.for f in run-mummer1 run-mummer3 nucmer promer exact-tandems 	  \
	mapview mummerplot nucmer2xfig
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/mummer
.endfor
	cd ${WRKSRC}/docs && pax -wr -s ',^Makefile$$,,' * \
		${DESTDIR}${PREFIX}/share/doc/mummer

.include "../../mk/bsd.pkg.mk"
