# $NetBSD: Makefile,v 1.6 2007/05/18 10:03:31 peter Exp $

DISTNAME=	qstat-2.10
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qstat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qstat.org/
COMMENT=	Program that gathers real-time statistics from game servers

INSTALLATION_DIRS=	bin

GNU_CONFIGURE=	yes
CPPFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR:Q}\""

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/qstat.cfg ${PKG_SYSCONFDIR}/qstat.cfg

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}/template
	${INSTALL_PROGRAM} ${WRKSRC}/qstat ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qstatdoc.html ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/template/*.html ${PREFIX}/share/doc/${PKGBASE}/template
	${INSTALL_DATA} ${WRKSRC}/contrib.cfg ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/qstat.cfg ${EGDIR}

.include "../../mk/bsd.pkg.mk"
