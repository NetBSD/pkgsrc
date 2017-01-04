# $NetBSD: Makefile,v 1.28 2017/01/04 20:01:39 roy Exp $

DISTNAME=	ncftp-3.2.5-src
PKGNAME=	${DISTNAME:S/ncftp/ncftp3/:S/-src//}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ncftp.com/
COMMENT=	FTP replacement with advanced user interface
LICENSE=	artistic

INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
GNU_CONFIGURE=	yes

post-patch:
	${MV} ${WRKSRC}/ncftp/pref.h ${WRKSRC}/ncftp/pref.h.in
	${SED} -e "s:/etc/ncftp.firewall:${PREFIX}/etc/ncftp.firewall:" \
		< ${WRKSRC}/ncftp/pref.h.in > ${WRKSRC}/ncftp/pref.h

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
