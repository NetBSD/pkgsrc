# $NetBSD: Makefile,v 1.7 2001/03/23 23:33:12 taca Exp $
#

DISTNAME=		ipadic-2.4.4
CATEGORIES=		japanese
MASTER_SITES=		http://chasen.aist-nara.ac.jp/stable/ipadic/

MAINTAINER=     	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=       	http://chasen.aist-nara.ac.jp/
COMMENT=		Japanese Morphological Dictionary for ChaSen

BUILD_DEPENDS=	${LOCALBASE}/libexec/chasen/makemat:../../japanese/chasen-base

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/chasenrc \
		${LOCALBASE}/share/chasen/dic/ipadic/chasenrc.example

.include "../../mk/bsd.pkg.mk"
