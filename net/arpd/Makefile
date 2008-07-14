# $NetBSD: Makefile,v 1.16 2008/07/14 12:56:09 joerg Exp $
#

DISTNAME=	arpd
PKGNAME=	arpd-1.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://subzero.campus.luth.se/pub/arpd/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	ARP daemon

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	Interix-*-* # does not have bpf(4) device

MAKE_ENV+=	BINDIR=${PREFIX}/sbin
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}

INSTALLATION_DIRS=	sbin share/doc ${PREFIX}/etc

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/arpd.README
	${INSTALL_DATA} ${WRKSRC}/arpd.conf ${DESTDIR}${PREFIX}/etc/arpd.conf.example

.include "../../mk/bsd.pkg.mk"
