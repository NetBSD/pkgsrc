# $NetBSD: Makefile,v 1.7 2004/04/25 08:11:38 snj Exp $
#

DISTNAME=	arpd
PKGNAME=	arpd-1.0
CATEGORIES=	net
MASTER_SITES=	ftp://subzero.campus.luth.se/pub/arpd/

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	ARP daemon

USE_BUILDLINK3=	yes

MAKE_ENV+=	BINDIR=${PREFIX}/sbin

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/arpd.README
	${INSTALL_DATA} ${WRKSRC}/arpd.conf ${PREFIX}/etc/arpd.conf.example

.include "../../mk/bsd.pkg.mk"
