# $NetBSD: Makefile,v 1.5 2002/03/23 01:56:28 wiz Exp $
#

DISTNAME=		csound-manual-4.10
PKGREVISION=		1
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
			toots.zip

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.csound.org
COMMENT=		Manuals and examples for Csound

LICENSE=		csound-license
RESTRICTED=		"no for-fee-redistribution"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
DIST_SUBDIR=		csound-4.10

NO_BUILD=		yes
WRKSRC=			${WRKDIR}
# default -a in options wreaks havoc on pdfs in the zips
EXTRACT_CMD=		unzip -Lq ${DOWNLOADED_DISTFILE}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/csound
	cd ${WRKSRC} && ${INSTALL_DATA} manual.txt spanish4.pdf manual.pdf \
		manual1.pdf manual2.pdf spplmnt.pdf spplmnt1.pdf spplmnt2.pdf \
		spplmnt.txt \
		${PREFIX}/share/doc/csound
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/csound
	cd ${WRKSRC} && ${PAX} -rw appendix command control cscore durctl \
		gen midi misc pchcnv pgmctl preface qr score siggen sigio \
		sigmod spectral syntax utility valcnv zak *.htm *.gif \
		${PREFIX}/share/doc/html/csound
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/csound
	cd ${WRKSRC} && ${INSTALL_DATA} hellorcb.aif toot* \
		${PREFIX}/share/examples/csound
	cd ${FILESDIR} && ${INSTALL_DATA} rt-midi-input.* \
		${PREFIX}/share/examples/csound

.include "../../mk/bsd.pkg.mk"
