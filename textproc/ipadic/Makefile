# $NetBSD: Makefile,v 1.8 2004/10/03 00:18:19 tv Exp $
#

DISTNAME=		ipadic-2.7.0
PKGREVISION=	1
CATEGORIES=		japanese textproc
MASTER_SITES=		http://chasen.aist-nara.ac.jp/stable/ipadic/

MAINTAINER=     	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=       	http://chasen.aist-nara.ac.jp/
COMMENT=		Japanese Morphological Dictionary for ChaSen

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
CONF_FILES=		${CHASEN_DICDIR}/ipadic/chasenrc.example \
			${PKG_SYSCONFDIR}/chasenrc

DOCDIR=			${PREFIX}/share/doc/chasen
DOCS=			AUTHORS COPYING ChangeLog NEWS doc/ipadic-ja.pdf

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/chasenrc \
		${CHASEN_DICDIR}/ipadic/chasenrc.example

.include "../../textproc/chasen/Makefile.common"
.include "../../textproc/chasen-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
