# $NetBSD: Makefile,v 1.3 2023/09/09 13:04:29 mef Exp $

DISTNAME=	tamago-tsunagi-5.0.7.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_OSDN:=tamago-tsunagi/62701/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ja.osdn.net/projects/tamago-tsunagi/
COMMENT=	IM(egg) for (Free)Wnn, Canna, sj3 and Anthy
LICENSE=	gnu-gpl-v2

CONFLICTS=	tamago-anthy-[0-9]*
CONFLICTS+=	tamago-[0-9]*

GNU_CONFIGURE=		yes

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
