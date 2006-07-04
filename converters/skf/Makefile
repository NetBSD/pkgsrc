# $NetBSD: Makefile,v 1.4 2006/07/04 15:44:13 yyamano Exp $

DISTNAME=	skf_1.93.10
PKGNAME=	skf-1.93.10
CATEGORIES=	japanese converters
MASTER_SITES=	http://download.sourceforge.jp/skf/20800/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://sourceforge.jp/projects/skf/
COMMENT=	Simple Kanji Filter - i18n kanji converter

WRKSRC=		${WRKDIR}/skf-1.93
INSTALL_TARGET=	install locale_install

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes
MANCOMPRESSED=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
