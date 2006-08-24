# $NetBSD: Makefile,v 1.5 2006/08/24 15:45:05 taca Exp $

DISTNAME=	skf_1.93.11
PKGNAME=	skf-1.93.11
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=skf/21441/}

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
