# $NetBSD: Makefile,v 1.1.1.1 2006/01/31 03:35:25 minskim Exp $

DISTNAME=	skf_1.93.9
PKGNAME=	skf-1.93.9
CATEGORIES=	japanese converters
MASTER_SITES=	http://download.sourceforge.jp/skf/17934/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://sourceforge.jp/projects/skf/
COMMENT=	Simple Kanji Filter - i18n kanji converter

WRKSRC=		${WRKDIR}/skf-1.93
INSTALL_TARGET=	install locale_install

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
MANCOMPRESSED=		yes
BUILD_USES_MSGFMT=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
