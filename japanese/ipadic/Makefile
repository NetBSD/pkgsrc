# $NetBSD: Makefile,v 1.4 2001/02/24 03:29:53 taca Exp $
#

DISTNAME=		ipadic-2.4.2
CATEGORIES=		japanese
MASTER_SITES=		http://chasen.aist-nara.ac.jp/stable/ipadic/

MAINTAINER=     	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=       	http://chasen.aist-nara.ac.jp/
COMMENT=		Japanese Morphological Dictionary for ChaSen

DEPENDS=        	chasen-base>=2.2.1:../../japanese/chasen-base

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
