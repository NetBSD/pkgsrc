# $NetBSD: Makefile,v 1.31 2018/11/14 22:21:31 kleink Exp $

DISTNAME=	kanatest-0.4.8
PKGREVISION=	28
CATEGORIES=	games
MASTER_SITES=	http://clayo.org/kanatest/
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://clayo.org/kanatest/
COMMENT=	Flash-card program to memorise Japanese kana

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake msgfmt pkg-config

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

post-build:
	cd ${WRKSRC}/po && for a in *.po; do msgfmt -o $${a%.po}.mo $$a; done

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
