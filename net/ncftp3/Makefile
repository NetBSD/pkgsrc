# $NetBSD: Makefile,v 1.8 2003/03/29 12:41:59 jmmv Exp $

DISTNAME=	ncftp-3.0.3-src
PKGNAME=	ncftp3-3.0.3
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.ncftp.com/
COMMENT=	FTP replacement with advanced user interface

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

post-patch:
	@${MV} ${WRKSRC}/ncftp/pref.h ${WRKSRC}/ncftp/pref.h.in
	@${SED} -e "s:/etc/ncftp.firewall:${PREFIX}/etc/ncftp.firewall:" \
		< ${WRKSRC}/ncftp/pref.h.in > ${WRKSRC}/ncftp/pref.h

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
