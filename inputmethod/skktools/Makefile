# $NetBSD: Makefile,v 1.1.1.1 2010/07/17 08:36:41 obache Exp $
#

DISTNAME=	skktools-1.3.1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/skk/tools/

MAINTAINER=	ryo_on@yk.rim.or.jp
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
