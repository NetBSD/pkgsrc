# $NetBSD: Makefile,v 1.5.2.1 2003/12/07 12:20:07 agc Exp $
#

DISTNAME=	xjdic23
PKGNAME=	xjdic-2.3
PKGREVISION=	2
WRKSRC=		${WRKDIR}
CATEGORIES=	japanese misc
MASTER_SITES=	http://www.bcit-broadcast.com/monash/
EXTRACT_SUFX=	.tgz
DISTFILES+=	edict.gz \
		kanjidic.gz \
		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~jwb/xjdic/
COMMENT=	Japanese dictionary

MESSAGE_SUBST+=	PREFIX=${PREFIX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

DIST_SUBDIR=	${PKGNAME}

do-install:
		cd ${WRKSRC} ; \
		for i in exjdxgen xjdic_cl xjdic_sa xjdserver xjdxgen ; \
		do \
			${INSTALL_PROGRAM} $$i ${PREFIX}/bin ; \
		done
		${MV} ${PREFIX}/bin/xjdic_sa ${PREFIX}/bin/xjdic
		${INSTALL_DATA_DIR} ${PREFIX}/share/xjdic
		${INSTALL_DATA} \
			${WRKSRC}/kanjstroke \
			${WRKSRC}/radicals.tm \
			${WRKSRC}/radkfile \
			${WRKSRC}/romkana.cnv \
			${WRKSRC}/vconj \
			${PREFIX}/share/xjdic
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/xjdic
		${INSTALL_MAN} \
			${WRKSRC}/xjdic22.WHATSNEW \
			${WRKSRC}/xjdic23.WHATSNEW \
			${WRKSRC}/xjdic23.inf \
			${WRKSRC}/xjdic23.install \
			${PREFIX}/share/doc/xjdic
		${INSTALL_MAN} ${WRKSRC}/xjdic.1 ${PREFIX}/man/man1
		${GZIP_CMD} -cd ${DISTDIR}/${DIST_SUBDIR}/kanjidic.gz \
			>${PREFIX}/share/xjdic/kanjidic
		${GZIP_CMD} -cd ${DISTDIR}/${DIST_SUBDIR}/edict.gz \
			>${PREFIX}/share/xjdic/edict
		${PREFIX}/bin/xjdxgen ${PREFIX}/share/xjdic/edict
		${PREFIX}/bin/xjdxgen ${PREFIX}/share/xjdic/kanjidic
		${SED} \
			-e 's,/home/jwb/nihongo/dics,${PREFIX}/share/xjdic,' \
			-e '/^kdicfile/s/kanjidic_b/kanjidic/' \
			< ${WRKSRC}/.xjdicrc.skel >${PREFIX}/share/doc/xjdic/.xjdicrc

.include "../../mk/bsd.pkg.mk"
