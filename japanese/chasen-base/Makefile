# $NetBSD: Makefile,v 1.1.1.1 2001/01/10 14:45:03 taca Exp $
#

DISTNAME=		chasen-${CHASEN_VERSION}
PKGNAME=		chasen-base-${CHASEN_VERSION}
CATEGORIES=		japanese
MASTER_SITES=		http://chasen.aist-nara.ac.jp/stable/chasen/

MAINTAINER=		tech-pkg-ja@jp.netbsd.org
HOMEPAGE=		http://chasen.aist-nara.ac.jp/

CHASEN_VERSION=		2.2.1

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	mkdir ${LOCALBASE}/share/chasen/dic

.include "../../mk/bsd.pkg.mk"
