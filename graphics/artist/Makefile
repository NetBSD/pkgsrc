# $NetBSD: Makefile,v 1.17 2026/10/06 19:46:12 wiz Exp $

DISTNAME=	artist-1.2.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.lysator.liu.se/~tab/artist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.lysator.liu.se/~tab/artist/
COMMENT=	Elisp drawing package with mouse and keyboard support
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS+=	${DOCDIR} \
			${EMACS_LISPPREFIX:C|^${PREFIX}/||}/artist

GNU_CONFIGURE=		yes

EMACS_VERSIONS_INCOMPATIBLE=	xemacs214 xemacs215 xemacs214nox xemacs215nox

.include "../../editors/emacs/modules.mk"

MAKE_FLAGS+=	EMACS=${EMACS_BIN} \
		lispdir=${DESTDIR}${EMACS_LISPPREFIX}/artist

DOCS=		BUGS COPYING ChangeLog INSTALL README TODO
DOCDIR=		share/doc/artist

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
