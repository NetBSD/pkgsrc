# $NetBSD: Makefile,v 1.6 2006/10/01 15:09:15 obache Exp $

DISTNAME=	skf_1.94.0
PKGNAME=	skf-1.94.0
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=skf/22014/}

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
