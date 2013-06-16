# $NetBSD: Makefile,v 1.25 2013/06/16 07:37:45 ryoon Exp $

DISTNAME=	ncftp-3.2.5-src
PKGNAME=	${DISTNAME:S/ncftp/ncftp3/:S/-src//}
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

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
