# $NetBSD: Makefile,v 1.2 1999/06/08 09:57:48 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.14 1998/04/05 04:46:33 max Exp $

DISTNAME=	kakasi-2.2.5
CATEGORIES=	japanese
MASTER_SITES=	ftp://sunsite.sut.ac.jp/pub/asia-info/japanese-src/packages/ \
	ftp://ftp.kusastro.kyoto-u.ac.jp/pub/baba/wais/ \
		ftp://etlport.etl.go.jp/pub/mule/contrib/ \
		ftp://ftp.cs.buffalo.edu/pub/mule/contrib/ \
		ftp://sh.wide.ad.jp/JAPAN/mule/contrib/ \
		ftp://ftp.funet.fi/pub/gnu/funet/emacs/mule/contrib/ \
		ftp://ftp.iij.ad.jp/pub/misc/mule/contrib/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} kakasidict.940620.gz \
		kakasi-ext.tar.gz

PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.netbsd.org

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} kakasi-ext.tar.gz
WRKSRC=		${WRKDIR}/${DISTNAME}/src
post-extract:
	@${GZCAT} ${DISTDIR}/kakasidict.940620.gz > ${WRKSRC}/kakasidict

pre-patch:
	@${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/kakasi-ext/patch.kakasi-2.2.5

post-install:
	${INSTALL_MAN} ${WRKSRC}/kakasi.1 ${PREFIX}/man/ja_JP.EUC/man1
	${MKDIR} ${PREFIX}/share/doc/kakasi
	${INSTALL_DATA} ${WRKSRC}/JISYO ${PREFIX}/share/doc/kakasi
	${INSTALL_DATA} ${WRKSRC}/../README* ${PREFIX}/share/doc/kakasi
	${INSTALL_DATA} ${WRKDIR}/kakasi-ext/KAKASI.DOC \
	  ${PREFIX}/share/doc/kakasi/kakasi-ext.doc

.include "../../mk/bsd.pkg.mk"
