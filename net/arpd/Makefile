# $NetBSD: Makefile,v 1.13 2007/03/24 19:21:28 joerg Exp $
#

DISTNAME=	arpd
PKGNAME=	arpd-1.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://subzero.campus.luth.se/pub/arpd/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	ARP daemon

NOT_FOR_PLATFORM=	Interix-*-* # does not have bpf(4) device

MAKE_ENV+=	BINDIR=${PREFIX}/sbin
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}

INSTALLATION_DIRS=	share/doc ${PREFIX}/etc

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/arpd.README
	${INSTALL_DATA} ${WRKSRC}/arpd.conf ${PREFIX}/etc/arpd.conf.example

.include "../../mk/bsd.pkg.mk"
