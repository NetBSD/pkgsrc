# $NetBSD: Makefile,v 1.1.1.1 2008/04/06 11:50:36 obache Exp $
#

DISTNAME=	Geomyidae-0.11
CATEGORIES=	net
MASTER_SITES=	http://www.r-36.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jgw@freeshell.org
HOMEPAGE=	http://www.r-36.net/
COMMENT=	Gopher daemon for Linux/BSD

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes

EGDIR=		${PREFIX}/share/examples/Geomyidae
DOCDIR=		${PREFIX}/share/doc/Geomyidae
RCD_SCRIPTS=	Geomyidae

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 ${EGDIR} ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Geomyidae ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/Geomyidae.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/index.gph ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
