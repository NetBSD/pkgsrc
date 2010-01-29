# $NetBSD: Makefile,v 1.14 2010/01/29 16:38:20 joerg Exp $
#

DISTNAME=	qpage-3.3
CATEGORIES=	comms
MASTER_SITES=	http://www.qpage.org/download/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qpage.org/
COMMENT=	Simple and efficient paging (SNPP) client and server

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	MKDIR_PATH=${MKDIR:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qpage ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qpage.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/qpage.1

.include "../../mk/bsd.pkg.mk"
