# $NetBSD: Makefile,v 1.6 2026/09/25 09:48:09 wiz Exp $

DISTNAME=	tamago-tsunagi-5.0.7.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	3
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_OSDN:=tamago-tsunagi/62701/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://ja.osdn.net/projects/tamago-tsunagi/
COMMENT=	IM(egg) for (Free)Wnn, Canna, sj3 and Anthy
LICENSE=	gnu-gpl-v2

CONFLICTS=	tamago-anthy-[0-9]*
CONFLICTS+=	tamago-[0-9]*

MAKE_FLAGS+=	EMACS=${EMACS_BIN}

EMACS_VERSIONS_INCOMPATIBLE=	emacs20 xemacs214 xemacs215 xemacs214nox xemacs215nox

GNU_CONFIGURE=		yes
INSTALL_MAKE_FLAGS+=	lispdir=${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
