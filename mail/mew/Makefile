# $NetBSD: Makefile,v 1.71 2006/10/19 19:50:08 wiz Exp $

DISTNAME=	mew-5.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	http://www.mew.org/Release/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.mew.org/
COMMENT=	Messaging in the Emacs World

CONFLICTS+=	mew-xemacs-[0-9]* incm-[0-9]*

INFO_FILES=	yes

HAS_CONFIGURE=	yes

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20 xemacs214 xemacs215
EMACS_MODULES+=			base

MEW_CONTRIB_DIR=${EMACS_LISPPREFIX}/mew/contrib

MAKE_FLAGS+=	prefix=${PREFIX:Q}
MAKE_FLAGS+=	EMACS=${EMACS_BIN:Q}
MAKE_FLAGS+=	elispdir=${EMACS_LISPPREFIX}/mew
MAKE_FLAGS+=	etcdir=${PREFIX}/share/mew
MAKE_FLAGS+=	infodir=${EMACS_INFOPREFIX}
MAKE_FLAGS+=	mandir=${PREFIX:Q}/${PKGMANDIR:Q}/man1

SUBST_CLASSES+=		local
SUBST_STAGE.local=	post-configure
SUBST_FILES.local=	Makefile bin/configure info/Makefile
SUBST_SED.local=	-e 's|/usr/local|${PREFIX}|g'

post-install:
	${INSTALL_DATA_DIR} ${MEW_CONTRIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${MEW_CONTRIB_DIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
