# $NetBSD: Makefile,v 1.2 2022/04/14 14:31:09 nikita Exp $

DISTNAME=		bbdb-3.2.2a
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
CONFLICTS+=		bbdb-[0-9]*

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		makeinfo autoconf automake autoreconf
INFO_FILES=		yes
LISPDIR=		${EMACS_LISPPREFIX}/bbdb
INSTALLATION_DIRS=	${EMACS_INFOPREFIX}

pre-configure:
	cd ${WRKSRC} && autoreconf --verbose --install

do-install:
	${MKDIR} ${DESTDIR}${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${DESTDIR}${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.elc ${DESTDIR}${LISPDIR}
	cd ${WRKSRC} && for f in bbdb.info; do	\
		${TEST} ! -f doc/"$$f" ||					\
		${INSTALL_DATA} doc/"$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};\
	done

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
