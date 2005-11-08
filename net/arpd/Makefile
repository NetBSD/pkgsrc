# $NetBSD: Makefile,v 1.10 2005/11/08 15:41:20 tv Exp $
#

DISTNAME=	arpd
PKGNAME=	arpd-1.0
CATEGORIES=	net
MASTER_SITES=	ftp://subzero.campus.luth.se/pub/arpd/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	ARP daemon

NOT_FOR_PLATFORM=	Interix-*-* # does not have bpf(4) device

MAKE_ENV+=	BINDIR=${PREFIX}/sbin

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/arpd.README
	${INSTALL_DATA} ${WRKSRC}/arpd.conf ${PREFIX}/etc/arpd.conf.example

.include "../../mk/bsd.pkg.mk"
