# $NetBSD: Makefile,v 1.16 2012/10/25 06:55:56 asau Exp $
#

DISTNAME=	ipadic-2.7.0
PKGREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	http://chasen.aist-nara.ac.jp/stable/ipadic/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=ipadic/24435/}

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://chasen-legacy.sourceforge.jp/
COMMENT=	Japanese Morphological Dictionary including parameter for ChaSen

GNU_CONFIGURE=	yes
CONF_FILES=	${PREFIX}/${CHASEN_DICDIR}/ipadic/chasenrc.example \
		${PKG_SYSCONFDIR}/chasenrc

DOCDIR=		share/doc/chasen
DOCS=		AUTHORS COPYING ChangeLog NEWS doc/ipadic-ja.pdf

INSTALLATION_DIRS=	${DOCDIR}

MAKE_JOBS_SAFE=		no

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/chasenrc \
		${DESTDIR}${PREFIX}/${CHASEN_DICDIR}/ipadic/chasenrc.example

.include "../../textproc/chasen/Makefile.common"
.include "../../textproc/chasen-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
