# $NetBSD: Makefile,v 1.2 2001/02/16 15:25:18 wiz Exp $
#

DISTNAME=		ipadic-2.4.1
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
	${INSTALL} -c -m ${NONBINMODE} -o ${BINOWN} -g ${BINGRP} \
		${WRKSRC}/chasenrc \
		${LOCALBASE}/share/chasen/dic/ipadic/chasenrc.example
	test -f ${LOCALBASE}/etc/chasenrc || \
		${INSTALL} -c -m ${NONBINMODE} -o ${BINOWN} -g ${BINGRP} \
			${WRKSRC}/chasenrc ${LOCALBASE}/etc

.include "../../mk/bsd.pkg.mk"
