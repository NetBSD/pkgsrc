# $NetBSD: Makefile,v 1.9 2008/10/11 09:31:56 uebayasi Exp $

DISTNAME=	artist-1.2.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.lysator.liu.se/~tab/artist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/~tab/artist/
COMMENT=	Elisp drawing package with mouse and keyboard support

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	${DOCDIR} \
			${EMACS_LISPPREFIX:C|^${PREFIX}/||}/artist

GNU_CONFIGURE=		yes

.include "../../editors/emacs/modules.mk"

MAKE_FLAGS+=	EMACS=${EMACS_FLAVOR} \
		lispdir=${DESTDIR}${EMACS_LISPPREFIX}/artist

DOCS=		BUGS COPYING ChangeLog INSTALL README TODO
DOCDIR=		share/doc/artist

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
