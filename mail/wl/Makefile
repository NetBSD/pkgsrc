# $NetBSD: Makefile,v 1.6 2001/11/29 01:12:40 hubertf Exp $

DISTNAME=	wl-2.6.0
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ring.gr.jp/pub/text/elisp/wl/stable/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.gohome.org/wl/
COMMENT=	mail/news management system with IMAP4rev1 support for Emacs

DEPENDS+=	semi>=1.13.7:../../devel/semi

INSTALL_TARGET=	install install-info
INFO_FILES=	wl.info wl-ja.info

DOCDIR=		${PREFIX}/share/doc/wl
EXAMPLESDIR=	${PREFIX}/share/examples/wl
DOCS=		BUGS NEWS README
DOCS_JA=	BUGS.ja NEWS.ja README.ja doc/TODO.ja
EXAMPLES=	dot.addresses dot.folders dot.wl

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/en
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCDIR}/en
.endfor
	${INSTALL_DATA_DIR} ${DOCDIR}/ja
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCDIR}/ja
.endfor
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}/en
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}/ja
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/en/$f ${EXAMPLESDIR}/en
	${INSTALL_DATA} ${WRKSRC}/samples/ja/$f ${EXAMPLESDIR}/ja
.endfor

.include "../../mk/bsd.pkg.mk"
