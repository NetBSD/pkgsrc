# $NetBSD: Makefile,v 1.12 2002/02/09 07:36:58 taca Exp $
#

DISTNAME=		ipadic-2.4.4
CATEGORIES=		japanese
MASTER_SITES=		http://chasen.aist-nara.ac.jp/stable/ipadic/

MAINTAINER=     	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=       	http://chasen.aist-nara.ac.jp/
COMMENT=		Japanese Morphological Dictionary for ChaSen

DEPENDS=		chasen-base>=2.2.5:../../japanese/chasen-base

GNU_CONFIGURE=		# defined
CONF_FILES=		${CHASEN_DICDIR}/chasenrc.example \
			${CHASEN_CONFDIR}/chasenrc

post-install:
	${INSTALL_DATA} ${WRKSRC}/chasenrc \
		${LOCALBASE}/share/chasen/dic/ipadic/chasenrc.example

.include "../chasen/Makefile.common"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
