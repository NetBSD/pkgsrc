# $NetBSD: Makefile,v 1.5 2003/08/05 21:34:10 seb Exp $
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

USE_NEW_TEXINFO=	YES
INFO_FILES=		ipadic-ja.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/chasenrc \
		${CHASEN_DICDIR}/ipadic/chasenrc.example

.include "../../textproc/chasen/Makefile.common"
.include "../../mk/bsd.pkg.mk"
