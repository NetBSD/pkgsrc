# $NetBSD: Makefile,v 1.6 2005/08/28 04:25:29 uebayasi Exp $

DISTNAME=	artist-1.2.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://www.lysator.liu.se/~tab/artist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/~tab/artist/
COMMENT=	Elisp drawing package with mouse and keyboard support

GNU_CONFIGURE=		yes

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "xemacs"
MAKE_FLAGS+=	EMACS=xemacs
MAKE_FLAGS+=	lispdir=${EMACS_LISPPREFIX}/artist
.endif

DOCS=		BUGS COPYING ChangeLog INSTALL README TODO
DOCDIR=		${PREFIX}/share/doc/artist

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
