# $NetBSD: Makefile,v 1.8 2005/02/21 20:26:12 hubertf Exp $
#

DISTNAME=	arpd
PKGNAME=	arpd-1.0
CATEGORIES=	net
MASTER_SITES=	ftp://subzero.campus.luth.se/pub/arpd/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	ARP daemon

USE_BUILDLINK3=	yes

MAKE_ENV+=	BINDIR=${PREFIX}/sbin

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/arpd.README
	${INSTALL_DATA} ${WRKSRC}/arpd.conf ${PREFIX}/etc/arpd.conf.example

.include "../../mk/bsd.pkg.mk"
