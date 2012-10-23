# $NetBSD: Makefile,v 1.18 2012/10/23 17:18:10 asau Exp $
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

INSTALLATION_DIRS=	sbin share/doc ${PREFIX}/etc

.include "../../mk/bsd.prefs.mk"

# Bogus warning from GCC 4.5
.if ${OPSYS} == "NetBSD"
BUILDLINK_TRANSFORM+=	rm:-Werror
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/arpd.README
	${INSTALL_DATA} ${WRKSRC}/arpd.conf ${DESTDIR}${PREFIX}/etc/arpd.conf.example

.include "../../mk/bsd.pkg.mk"
