# $NetBSD: Makefile,v 1.3 2011/04/22 14:40:43 obache Exp $
#

DISTNAME=	skktools-1.3.1
PKGREVISION=	1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/skk/tools/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/
COMMENT=	SKK dictionary manipulation tools

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	skkserv<3.9.4nb7

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-gdbm

.include "options.mk"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	configure
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|g'

.include "../../mk/bsd.pkg.mk"
