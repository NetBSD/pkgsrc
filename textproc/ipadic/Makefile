# $NetBSD: Makefile,v 1.4 2003/07/17 22:54:21 grant Exp $
#

DISTNAME=		ipadic-2.4.4
PKGREVISION=		1
CATEGORIES=		japanese textproc
MASTER_SITES=		http://chasen.aist-nara.ac.jp/stable/ipadic/

MAINTAINER=     	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=       	http://chasen.aist-nara.ac.jp/
COMMENT=		Japanese Morphological Dictionary for ChaSen

DEPENDS=		chasen-base>=2.2.5:../../textproc/chasen-base

GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
CONF_FILES=		${CHASEN_DICDIR}/ipadic/chasenrc.example \
			${CHASEN_CONFDIR}/chasenrc

post-install:
	${INSTALL_DATA} ${WRKSRC}/chasenrc \
		${CHASEN_DICDIR}/ipadic/chasenrc.example

.include "../../textproc/chasen/Makefile.common"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
