# $NetBSD: Makefile,v 1.23 2026/01/04 06:19:39 riastradh Exp $

DISTNAME=		netpgpverify-${VERSION}
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		Standalone PGP and ssh signature verification utility
LICENSE=		modified-bsd

AUTO_MKDIRS=		yes
GNU_CONFIGURE=		yes

TEST_TARGET=		tst

.include "../../mk/bsd.prefs.mk"

VERSION!=	${AWK} '/\#define.*NETPGP_VERIFY_H_/ {print $$3}' ${FILESDIR}/verify.h

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
