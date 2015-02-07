# $NetBSD: Makefile,v 1.5 2015/02/07 15:02:04 darcy Exp $
#

DISTNAME=	ccxstream-1.0.15
CATEGORIES=	audio multimedia net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xbplayer/}

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://www.xbmc.org/
COMMENT=	Program for streaming multimedia content to XBMC over XBMSP protocol
#LICENSE=	# TODO: (see mk/license.mk)

RCD_SCRIPTS=		ccxstream
USE_TOOLS+=		gmake
DOCDIR=			share/doc/ccxstream
INSTALLATION_DIRS=	bin ${DOCDIR}

LDFLAGS.SunOS+=		-lsocket -lnsl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccxstream ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/ccxtest ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/xbmsp-rc ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/PORTING ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
