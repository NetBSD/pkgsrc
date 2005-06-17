# $NetBSD: Makefile,v 1.10 2005/06/17 03:50:23 jlam Exp $
#

DISTNAME=	xjdic24
PKGNAME=	xjdic-2.4
CATEGORIES=	japanese misc
MASTER_SITES=	ftp://ftp.cc.monash.edu.au/pub/nihongo/ \
		http://japanology.arts.kuleuven.ac.be/mirrors/monash/ \
		ftp://ftp.nrc.ca/pub/packages/nihongo/ \
		http://www.bcit-broadcast.com/monash/ \
		ftp://ftp.sedl.org/pub/mirrors/nihongo/ \
		ftp://ftp.net.usf.edu/pub/monash/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/nihongo/ftp.cc.monash.edu.au/ \
		ftp://ftp.funet.fi/pub/culture/japan/mirrors/monash/pub/nihongo/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~jwb/xjdic/
COMMENT=	Japanese dictionary

DEPENDS+=	edict-[0-9]*:../../misc/edict
DEPENDS+=	kanjidic-[0-9]*:../../misc/kanjidic

WRKSRC=		${WRKDIR}
MESSAGE_SUBST+=	PREFIX=${PREFIX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

INSTALLATION_DIRS=	bin man/man1

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
			${WRKSRC}/xjdic24.WHATSNEW \
			${WRKSRC}/xjdic24.inf \
			${WRKSRC}/xjdic24.install \
			${PREFIX}/share/doc/xjdic
		${INSTALL_MAN} ${WRKSRC}/xjdic.1 ${PREFIX}/man/man1
		${LN} -s ../edict/edict ${PREFIX}/share/xjdic/edict
		${LN} -s ../kanjidic/kanjidic ${PREFIX}/share/xjdic/kanjidic
		${PREFIX}/bin/xjdxgen ${PREFIX}/share/xjdic/edict
		${PREFIX}/bin/xjdxgen ${PREFIX}/share/xjdic/kanjidic
		${SED} \
			-e 's,/home/jwb/nihongo/dics,${PREFIX}/share/xjdic,' \
			-e '/^kdicfile/s/kanjidic_b/kanjidic/' \
			< ${WRKSRC}/.xjdicrc.skel >${PREFIX}/share/doc/xjdic/.xjdicrc

.include "../../mk/bsd.pkg.mk"
