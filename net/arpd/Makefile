# $NetBSD: Makefile,v 1.2 2001/02/17 18:18:33 wiz Exp $
#

DISTNAME=	arpd
PKGNAME=	arpd-1.0
CATEGORIES=	net
MASTER_SITES=	ftp://subzero.campus.luth.se/pub/arpd/

MAINTAINER=	hubertf@netbsd.org
COMMENT=	arp daemon

MAKE_ENV+=	BINDIR=${PREFIX}/sbin

post-install:
		${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/arpd.README
		${INSTALL_DATA} ${WRKSRC}/arpd.conf ${PREFIX}/etc/arpd.conf.example

.include "../../mk/bsd.pkg.mk"
