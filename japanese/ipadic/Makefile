# $NetBSD: Makefile,v 1.6 2001/02/28 14:58:54 taca Exp $
#

DISTNAME=		ipadic-2.4.3
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
	${TEST} -f ${LOCALBASE}/etc/chasenrc || \
		${INSTALL} -c -m ${NONBINMODE} -o ${BINOWN} -g ${BINGRP} \
			${WRKSRC}/chasenrc ${LOCALBASE}/etc

.include "../../mk/bsd.pkg.mk"
