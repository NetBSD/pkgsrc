# $NetBSD: Makefile,v 1.35 2012/03/17 15:03:29 obache Exp $

DISTNAME=	skf_${VERSION}.5
VERSION=	1.97
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=skf/55294/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/skf/
COMMENT=	Simple Kanji Filter - i18n kanji converter
#LICENSE=	modified-bsd # some files are derived from...see ${WRKSRC}/copywrite	

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/skf-${VERSION}
INSTALL_TARGET=	install locale_install

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt perl gzip
GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no

REPLACE_PERL=	scripts/parse_uni.p

PLIST_SUBST+=	VERSION=${VERSION}
PRINT_PLIST_AWK+=	{gsub(/${VERSION}/, "$${VERSION}");}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
