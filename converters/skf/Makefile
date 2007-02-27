# $NetBSD: Makefile,v 1.9 2007/02/27 02:29:40 obache Exp $

DISTNAME=	skf_1.94.7
PKGNAME=	skf-1.94.7
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=skf/24158/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://sourceforge.jp/projects/skf/
COMMENT=	Simple Kanji Filter - i18n kanji converter

WRKSRC=		${WRKDIR}/skf-1.94
INSTALL_TARGET=	install locale_install

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes
MANCOMPRESSED=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
