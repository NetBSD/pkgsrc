# $NetBSD: Makefile,v 1.4 2001/03/16 20:53:04 zuntum Exp $

DISTNAME=	ncftp-3.0.2-src
PKGNAME=	ncftp3-3.0.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.ncftp.com/
COMMENT=	FTP replacement with advanced user interface

DEPENDS+=	ncurses>=5.1:../../devel/ncurses

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
GNU_CONFIGURE=	yes

post-patch:
	@${MV} ${WRKSRC}/ncftp/pref.h ${WRKSRC}/ncftp/pref.h.in
	@${SED} -e "s:/etc/ncftp.firewall:${PREFIX}/etc/ncftp.firewall:" \
		< ${WRKSRC}/ncftp/pref.h.in > ${WRKSRC}/ncftp/pref.h

.include "../../mk/bsd.pkg.mk"
