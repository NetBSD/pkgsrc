# $NetBSD: Makefile,v 1.3 2002/01/27 19:33:03 jlam Exp $
#

DISTNAME=	arpd
PKGNAME=	arpd-1.0
CATEGORIES=	net
MASTER_SITES=	ftp://subzero.campus.luth.se/pub/arpd/

MAINTAINER=	hubertf@netbsd.org
COMMENT=	arp daemon

USE_BUILDLINK_ONLY=	yes

MAKE_ENV+=	BINDIR=${PREFIX}/sbin

post-install:
		${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/arpd.README
		${INSTALL_DATA} ${WRKSRC}/arpd.conf ${PREFIX}/etc/arpd.conf.example

.include "../../mk/bsd.pkg.mk"
