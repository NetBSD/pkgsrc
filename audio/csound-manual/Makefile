# $NetBSD: Makefile,v 1.1.1.1 2001/03/13 13:23:06 wiz Exp $
#

DISTNAME=		csound-manual-4.07
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.csounds.com/manual/current/
EXTRACT_SUFX=		.zip
DISTFILES=		ascii.zip \
			espanol.zip \
			html.zip \
			manual1.zip \
			manual2.zip \
			spplmnt1.zip \
			spplmnt2.zip \
			spplmtxt.zip \
			toots.zip \
			update1.zip \
			update2.zip

MAINTAINER=		collver@softhome.net
HOMEPAGE=		http://www.csound.org
COMMENT=		Manuals and examples for Csound

LICENSE=		csound-license
NO_SRC_ON_CDROM=	"no for-fee-redistribution"
NO_BIN_ON_CDROM=	${NO_SRC_ON_CDROM}
DIST_SUBDIR=		csound

NO_BUILD=		yes
WRKSRC=			${WRKDIR}
# default -a in options wreaks havoc on pdfs in the zips
EXTRACT_CMD=		unzip -Lq ${DOWNLOADED_DISTFILE}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/csound
	cd ${WRKSRC} && ${INSTALL_DATA} manual.txt spanish4.pdf manual.pdf \
		manual1.pdf manual2.pdf spplmnt.pdf spplmnt1.pdf spplmnt2.pdf \
		spplmnt.txt 4_07up.pdf 4_07up1.pdf 4_07up2.pdf \
		${PREFIX}/share/doc/csound
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/csound
	cd ${WRKSRC} && ${PAX} -rw appendix command control cscore durctl \
		gen midi misc pchcnv pgmctl preface qr score siggen sigio \
		sigmod spectral syntax utility valcnv zak *.htm *.gif \
		${PREFIX}/share/doc/html/csound
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/csound
	cd ${WRKSRC} && ${INSTALL_DATA} hellorcb.aif toot* \
		${PREFIX}/share/examples/csound

.include "../../mk/bsd.pkg.mk"
