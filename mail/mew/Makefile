# $NetBSD: Makefile,v 1.105 2023/09/03 23:53:41 taca Exp $

DISTNAME=	mew-6.9
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	http://www.mew.org/Release/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	https://www.mew.org/
COMMENT=	Messaging in the Emacs World
LICENSE=	modified-bsd

INSTALLATION_DIRS=	${MEW_CONTRIB_DIR:C|^${PREFIX}/||}

DEPENDS+=	${RUBY_PKGPREFIX}-sqlite3>=1.1:../../databases/ruby-sqlite3

CONFLICTS+=	mew-xemacs-[0-9]* incm-[0-9]*

INFO_FILES=	yes

GNU_CONFIGURE=	yes

EMACS_VERSIONS_ACCEPTED=	emacs29 emacs29nox
EMACS_VERSIONS_ACCEPTED=	emacs28 emacs28nox
EMACS_VERSIONS_ACCEPTED=	emacs27 emacs27nox
EMACS_VERSIONS_ACCEPTED=	emacs26 emacs26nox
EMACS_VERSIONS_ACCEPTED+=	emacs21 emacs21nox
EMACS_MODULES+=			base

MAKE_FLAGS+=		DESTDIR=${DESTDIR:Q}
MAKE_FLAGS+=		prefix=${PREFIX:Q}
MAKE_FLAGS+=		exec_prefix=${PREFIX:Q}
MAKE_FLAGS+=		EMACS=${EMACS_BIN:Q}
MAKE_FLAGS+=		elispdir=${EMACS_LISPPREFIX:Q}/mew
MAKE_FLAGS+=		etcdir=${EMACS_ETCPREFIX:Q}/mew
MAKE_FLAGS+=		infodir=${EMACS_INFOPREFIX:Q}
MAKE_FLAGS+=		mandir=${PREFIX:Q}/${PKGMANDIR:Q}/man1
CONFIGURE_ARGS+=	--with-etcdir=${EMACS_ETCPREFIX}/mew

ICONDIR=		${EMACS_ETCPREFIX}/mew

SUBST_CLASSES+=		icondir
SUBST_STAGE.icondir=	pre-configure
SUBST_FILES.icondir=	elisp/mew-key.el
SUBST_VARS.icondir=	ICONDIR

REPLACE_RUBY=		bin/cmew bin/smew

.include "../../devel/zlib/buildlink3.mk"
.include "../../editors/emacs/modules.mk"
.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
