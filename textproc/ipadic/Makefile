# $NetBSD: Makefile,v 1.1.1.1 2002/05/31 13:00:53 seb Exp $
#

DISTNAME=		ipadic-2.4.4
CATEGORIES=		japanese textproc
MASTER_SITES=		http://chasen.aist-nara.ac.jp/stable/ipadic/

MAINTAINER=     	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=       	http://chasen.aist-nara.ac.jp/
COMMENT=		Japanese Morphological Dictionary for ChaSen

DEPENDS=		chasen-base>=2.2.5:../../textproc/chasen-base

GNU_CONFIGURE=		# defined
CONF_FILES=		${CHASEN_DICDIR}/chasenrc.example \
			${CHASEN_CONFDIR}/chasenrc

post-install:
	${INSTALL_DATA} ${WRKSRC}/chasenrc \
		${LOCALBASE}/share/chasen/dic/ipadic/chasenrc.example

.include "../../textproc/chasen/Makefile.common"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
