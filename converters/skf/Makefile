# $NetBSD: Makefile,v 1.13 2008/01/21 02:06:49 obache Exp $

DISTNAME=	skf_1.95.3
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=skf/28214/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/skf/
COMMENT=	Simple Kanji Filter - i18n kanji converter

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/skf-1.95
INSTALL_TARGET=	install locale_install

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes
MANCOMPRESSED=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
