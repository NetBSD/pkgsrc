# $NetBSD: Makefile,v 1.3 1999/09/30 05:49:41 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.14 1998/04/05 04:46:33 max Exp $

DISTNAME=	kakasi-2.3.0
CATEGORIES=	japanese
MASTER_SITES=	ftp://kakasi.namazu.org/pub/kakasi/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} kakasidict.940620.gz

PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://kakasi.namazu.org/

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
ALL_TARGET=	all dict
INSTALL_TARGET=	install dict-install

post-extract:
	@${GZCAT} ${DISTDIR}/kakasidict.940620.gz > ${WRKSRC}/kakasidict

post-configure:
	@${RM} -f ${WRKSRC}/libtool
	@${LN} -s ${LIBTOOL} ${WRKSRC}/libtool

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/kakasi.1 ${PREFIX}/man/ja_JP.EUC/man1
	${INSTALL_MAN} ${WRKSRC}/doc/kakasi.cat ${PREFIX}/man/ja_JP.EUC/cat1

.include "../../mk/bsd.pkg.mk"
