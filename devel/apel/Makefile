# $NetBSD: Makefile,v 1.2 2001/10/21 09:54:19 wiz Exp $

DISTNAME=	apel-10.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/apel/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.kanji.zinbun.kyoto-u.ac.jp/~tomo/elisp/APEL/
COMMENT=	Portable Emacs Library

DEPENDS+=	emacs-20.7:../../editors/emacs

DOCDIR=		${PREFIX}/share/doc/apel

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.en ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
