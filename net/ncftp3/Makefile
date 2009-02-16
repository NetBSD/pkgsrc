# $NetBSD: Makefile,v 1.20 2009/02/16 18:44:40 joerg Exp $

DISTNAME=	ncftp-3.1.9-src
PKGNAME=	ncftp3-3.1.9
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.ncftp.com/
COMMENT=	FTP replacement with advanced user interface

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
GNU_CONFIGURE=	yes

post-patch:
	@${MV} ${WRKSRC}/ncftp/pref.h ${WRKSRC}/ncftp/pref.h.in
	@${SED} -e "s:/etc/ncftp.firewall:${PREFIX}/etc/ncftp.firewall:" \
		< ${WRKSRC}/ncftp/pref.h.in > ${WRKSRC}/ncftp/pref.h

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
