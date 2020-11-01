# $NetBSD: Makefile,v 1.22 2020/11/01 11:28:35 wiz Exp $

DISTNAME=		netpgpverify-${VERSION}
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
