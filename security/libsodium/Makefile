# $NetBSD: Makefile,v 1.2 2013/05/01 05:52:06 agc Exp $
#

DISTNAME=	libsodium-0.4.1
CATEGORIES=	security
MASTER_SITES=	http://download.dnscrypt.org/libsodium/releases/

MAINTAINER=	csosstudy@gmail.com
HOMEPAGE=	https://github.com/jedisct1/libsodium
COMMENT=	Library for build higher-level cryptographic tools
LICENSE=	isc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

TEST_TARGET=	check
AUTO_MKDIRS=	yes

DOCDIR=		share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
