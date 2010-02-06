# $NetBSD: Makefile,v 1.25 2010/02/06 11:26:44 obache Exp $

DISTNAME=	skf_${VERSION}.6
VERSION=	1.96
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=skf/45823/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/skf/
COMMENT=	Simple Kanji Filter - i18n kanji converter

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/skf-${VERSION}
INSTALL_TARGET=	install locale_install

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt perl
TOOLS_NOOP+=		gzip
GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no

REPLACE_PERL=	scripts/parse_uni.p

PLIST_SUBST+=	VERSION=${VERSION}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
