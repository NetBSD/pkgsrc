# $NetBSD: Makefile,v 1.9 2017/09/04 18:00:55 wiz Exp $

DISTNAME=	qstat-2.10
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qstat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.qstat.org/
COMMENT=	Program that gathers real-time statistics from game servers

GNU_CONFIGURE=	yes
CPPFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR:Q}\""

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/qstat.cfg ${PKG_SYSCONFDIR}/qstat.cfg

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/template
	${INSTALL_PROGRAM} ${WRKSRC}/qstat ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qstatdoc.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/template/*.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/template
	${INSTALL_DATA} ${WRKSRC}/contrib.cfg ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/qstat.cfg ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
