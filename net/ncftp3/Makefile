# $NetBSD: Makefile,v 1.1.1.1 2001/01/17 00:18:39 pooka Exp $

DISTNAME=	ncftp-3.0.2-src
PKGNAME=	ncftp3-3.0.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	zuntum@eik.pl
HOMEPAGE=	http://www.ncftp.com/

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
GNU_CONFIGURE=	yes

post-patch:
	@${MV} ${WRKSRC}/ncftp/pref.h ${WRKSRC}/ncftp/pref.h.in
	@${SED} -e "s:/etc/ncftp.firewall:${PREFIX}/etc/ncftp.firewall:" \
		< ${WRKSRC}/ncftp/pref.h.in > ${WRKSRC}/ncftp/pref.h

.include "../../mk/bsd.pkg.mk"
