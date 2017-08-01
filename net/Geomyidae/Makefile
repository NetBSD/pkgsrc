# $NetBSD: Makefile,v 1.8 2017/08/01 17:40:14 wiz Exp $

DISTNAME=	geomyidae-0.26.3
CATEGORIES=	net
#MASTER_SITES=	http://r-36.net/src/geomyidae/

MAINTAINER=	jgw@sdf.org
#HOMEPAGE=	http://r-36.net/src/geomyidae/
COMMENT=	Gopher daemon for Linux/BSD
LICENSE=	mit AND x11

NO_CONFIGURE=	yes

EGDIR=		${PREFIX}/share/examples/geomyidae
DOCDIR=		${PREFIX}/share/doc/geomyidae

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 ${EGDIR} ${EGDIR}/rc.d ${DOCDIR}

LDFLAGS.SunOS+=	-lsocket -lnsl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/geomyidae ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/geomyidae.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CGI ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/index.gph ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rc.d/* ${DESTDIR}${EGDIR}/rc.d

.include "../../mk/bsd.pkg.mk"
