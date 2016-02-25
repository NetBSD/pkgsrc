# $NetBSD: Makefile,v 1.19 2016/02/25 16:20:50 jperkin Exp $
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

# Bogus warning from GCC 4.5
BUILDLINK_TRANSFORM.NetBSD+=	rm:-Werror

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/arpd.README
	${INSTALL_DATA} ${WRKSRC}/arpd.conf ${DESTDIR}${PREFIX}/etc/arpd.conf.example

.include "../../mk/bsd.pkg.mk"
