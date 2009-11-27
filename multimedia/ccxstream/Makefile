# $NetBSD: Makefile,v 1.1.1.1 2009/11/27 08:38:49 wiz Exp $
#

DISTNAME=	ccxstream-1.0.15
CATEGORIES=	audio multimedia net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xbplayer/}

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://www.xbmc.org/
COMMENT=	Program for streaming multimedia content to XMBC over XBMSP protocol
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

RCD_SCRIPTS=		ccxstream
USE_TOOLS+=		gmake
DOCDIR=			share/doc/ccxstream
INSTALLATION_DIRS=	bin ${DOCDIR}

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

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
