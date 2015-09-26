# $NetBSD: Makefile,v 1.16.2.1 2015/09/26 06:04:13 ryoon Exp $

DISTNAME=		netpgpverify-20150919
CATEGORIES=		security
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Standalone PGP and ssh signature verification utility
LICENSE=		modified-bsd

AUTO_MKDIRS=		yes
GNU_CONFIGURE=		yes

TEST_TARGET=		tst

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
