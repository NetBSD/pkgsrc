# $NetBSD: Makefile,v 1.3 2001/11/29 01:12:49 hubertf Exp $
#

DISTNAME=		helpdc21
PKGNAME=		helpdeco-21
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SIMTEL:=win95/winhelp/}
EXTRACT_SUFX=		.zip

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.simtel.net/pub/pd/23694.shtml
COMMENT=		windows .hlp to .rtf converter

WRKSRC=			${WRKDIR}

LICENSE=		no-commercial-use

# from ftp://ftp.simtel.net/pub/simtelnet/MIRRORS.TXT
MASTER_SITE_SIMTEL+=	ftp://ftp.cdrom.com/pub/simtelnet/ \
			ftp://ftp.datacanyon.com/pub/simtelnet/ \
			ftp://ftp.digital.com/pub/micro/pc/simtelnet/ \
			ftp://ftp.usg.edu/pub/mirrors/simtelnet/ \
			ftp://uiarchive.cso.uiuc.edu/pub/systems/pc/simtelnet/ \
			ftp://ftp.bu.edu/pub/mirrors/simtelnet/ \
			ftp://simtel.klondyke.net/simtel/ \
			ftp://simtelnet.galilei.com/pub/simtelnet/ \
			ftp://ftp.rge.com/pub/systems/simtelnet/ \
			ftp://ftp.ou.edu/pub/simtelnet/ \
			ftp://ftp.orst.edu/pub/simtelnet/ \
			ftp://ftphost.simtel.net/pub/simtelnet/ \
			ftp://mirrors.aol.com/pub/simtelnet/ \
			ftp://ftp.simtel.net/pub/simtelnet/ \
			ftp://ftp.telusplanet.net/pub/simtelnet/ \
			ftp://ftp.crc.ca/pub/systems/ibmpc/simtelnet/ \
			ftp://ftp.direct.ca/pub/simtelnet/

post-extract:
	${RM} -f ${WRKSRC}/*exe
	${CP} ${FILESDIR}/helpdeco-de.txt \
		${FILESDIR}/helpdeco-en.txt \
		${FILESDIR}/compat.h \
		${FILESDIR}/compat.c \
		${WRKSRC}
	${SED} "s|PREFIX|${PREFIX}|" \
		<${FILESDIR}/Makefile \
		>${WRKSRC}/Makefile

do-install:
	${CP} ${WRKSRC}/splitmrb \
		${WRKSRC}/zapres \
		${WRKSRC}/helpdeco \
		${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/helpdeco
	${CP} ${WRKSRC}/helpdeco-de.txt \
		${WRKSRC}/helpdeco-en.txt \
		${WRKSRC}/helpfile.txt \
		${PREFIX}/share/doc/helpdeco

.include "../../mk/bsd.pkg.mk"
