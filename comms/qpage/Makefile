# $NetBSD: Makefile,v 1.15 2012/10/03 11:24:44 asau Exp $
#

DISTNAME=	qpage-3.3
CATEGORIES=	comms
MASTER_SITES=	http://www.qpage.org/download/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qpage.org/
COMMENT=	Simple and efficient paging (SNPP) client and server

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	MKDIR_PATH=${MKDIR:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qpage ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qpage.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/qpage.1

.include "../../mk/bsd.pkg.mk"
