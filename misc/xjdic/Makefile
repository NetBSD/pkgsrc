# $NetBSD: Makefile,v 1.19 2012/10/08 09:57:41 asau Exp $
#

DISTNAME=	xjdic24
PKGNAME=	xjdic-2.4
CATEGORIES=	japanese misc
MASTER_SITES=	http://japanology.arts.kuleuven.ac.be/mirrors/monash/ \
		ftp://ftp.nrc.ca/pub/packages/nihongo/ \
		http://www.bcit-broadcast.com/monash/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/nihongo/ftp.cc.monash.edu.au/ \
		ftp://ftp.funet.fi/pub/culture/japan/mirrors/monash/pub/nihongo/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~jwb/xjdic/
COMMENT=	Japanese dictionary

DEPENDS+=	edict-[0-9]*:../../misc/edict
DEPENDS+=	kanjidic-[0-9]*:../../misc/kanjidic

.include "options.mk"

WRKSRC=		${WRKDIR}
MESSAGE_SUBST+=	PREFIX=${PREFIX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC} ; \
	for i in exjdxgen xjdic_cl xjdic_sa xjdserver xjdxgen ; \
	do \
		${INSTALL_PROGRAM} $$i ${DESTDIR}${PREFIX}/bin ; \
	done
	${MV} ${DESTDIR}${PREFIX}/bin/xjdic_sa ${DESTDIR}${PREFIX}/bin/xjdic
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/xjdic
	${INSTALL_DATA} \
		${WRKSRC}/kanjstroke \
		${WRKSRC}/radicals.tm \
		${WRKSRC}/radkfile \
		${WRKSRC}/romkana.cnv \
		${WRKSRC}/vconj \
		${DESTDIR}${PREFIX}/share/xjdic
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/share/doc/xjdic
	${INSTALL_MAN} \
		${WRKSRC}/xjdic22.WHATSNEW \
		${WRKSRC}/xjdic23.WHATSNEW \
		${WRKSRC}/xjdic24.WHATSNEW \
		${WRKSRC}/xjdic24.inf \
		${WRKSRC}/xjdic24.install \
		${DESTDIR}${PREFIX}/share/doc/xjdic
	${INSTALL_MAN} ${WRKSRC}/xjdic.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${LN} -s ${PREFIX}/share/edict/edict ${DESTDIR}${PREFIX}/share/xjdic/edict
	${LN} -s ${PREFIX}/share/kanjidic/kanjidic ${DESTDIR}${PREFIX}/share/xjdic/kanjidic
	${DESTDIR}${PREFIX}/bin/xjdxgen ${DESTDIR}${PREFIX}/share/xjdic/edict
	${DESTDIR}${PREFIX}/bin/xjdxgen ${DESTDIR}${PREFIX}/share/xjdic/kanjidic
	${SED} \
		-e 's,/home/jwb/nihongo/dics,${PREFIX}/share/xjdic,' \
		-e '/^kdicfile/s/kanjidic_b/kanjidic/' \
		< ${WRKSRC}/.xjdicrc.skel \
		> ${DESTDIR}${PREFIX}/share/doc/xjdic/.xjdicrc

.include "../../mk/bsd.pkg.mk"
