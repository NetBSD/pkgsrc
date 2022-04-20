# $NetBSD: Makefile,v 1.3 2022/04/20 18:07:19 nikita Exp $

DISTNAME=		bbdb-3.2.2a
PKGREVISION=		1
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=		misc mail news
MASTER_SITES=		http://git.savannah.nongnu.org/cgit/bbdb.git/snapshot/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://elpa.gnu.org/packages/bbdb.html
COMMENT=		Insidious Big Brother DataBase (version 3)
LICENSE=		gnu-gpl-v3

# bbdb is included in xemacs-packages
# emacs 24 or newer
EMACS_VERSIONS_ACCEPTED=	emacs25 emacs25nox emacs26 emacs26nox
EMACS_VERSIONS_ACCEPTED+=	emacs27 emacs27nox emacs28 emacs28nox

CONFLICTS+=		xemacs-packages-[0-9]*

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf automake autoreconf
LISPDIR=		${EMACS_LISPPREFIX}/bbdb
INSTALLATION_DIRS=	${EMACS_INFOPREFIX}

# The info document is an example info document,
# no real documentary content yet. If this will
# change, remove this from doc/Makefile.am:
# doc_DATA = bbdb.pdf
#
# bbdb.info bbdb.pdf: $(bbdb_TEXINFOS)
CONFIGURE_ARGS+=	--enable-docs=no

pre-configure:
	cd ${WRKSRC} && autoreconf --verbose --install

do-install:
	${MKDIR} ${DESTDIR}${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${DESTDIR}${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.elc ${DESTDIR}${LISPDIR}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
