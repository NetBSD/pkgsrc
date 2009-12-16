# $NetBSD: Makefile,v 1.1.1.1 2009/12/16 23:55:13 joerg Exp $

DISTNAME=	kanatest-0.4.8
CATEGORIES=	games
MASTER_SITES=	http://clayo.org/kanatest/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://clayo.org/kanatest/
COMMENT=	A flash-card program to memorise Japanese kana

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake msgfmt pkg-config

post-build:
	cd ${WRKSRC}/po && for a in *.po; do msgfmt -o $${a%.po}.mo $$a; done

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
