# $NetBSD: Makefile,v 1.1.1.1 2000/08/27 20:43:24 hubertf Exp $
#

DISTNAME=	arpd
PKGNAME=	arpd-1.0
CATEGORIES=	net
MASTER_SITES=	ftp://subzero.campus.luth.se/pub/arpd/

MAINTAINER=	hubertf@netbsd.org

MAKE_ENV+=	BINDIR=${PREFIX}/sbin

post-install:
		${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/arpd.README
		${INSTALL_DATA} ${WRKSRC}/arpd.conf ${PREFIX}/etc/arpd.conf.example

.include "../../mk/bsd.pkg.mk"
