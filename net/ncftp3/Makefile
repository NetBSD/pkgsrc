# $NetBSD: Makefile,v 1.12 2003/09/27 22:57:32 wiz Exp $

DISTNAME=	ncftp-3.1.6-src
PKGNAME=	ncftp3-3.1.6
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.ncftp.com/
COMMENT=	FTP replacement with advanced user interface

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

post-patch:
	@${MV} ${WRKSRC}/ncftp/pref.h ${WRKSRC}/ncftp/pref.h.in
	@${SED} -e "s:/etc/ncftp.firewall:${PREFIX}/etc/ncftp.firewall:" \
		< ${WRKSRC}/ncftp/pref.h.in > ${WRKSRC}/ncftp/pref.h

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
