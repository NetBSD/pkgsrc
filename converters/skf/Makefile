# $NetBSD: Makefile,v 1.57 2019/08/11 13:18:16 wiz Exp $

DISTNAME=	skf_${VERSION}.4
VERSION=	2.00
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	3
CATEGORIES=	japanese converters
MASTER_SITES=	${MASTER_SITE_OSDN:=skf/64426/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://osdn.jp/projects/skf/
COMMENT=	Simple Kanji Filter - i18n kanji converter
#LICENSE=	modified-bsd # some files are derived from...see ${WRKSRC}/copyright
# 		and ${PREFIX}/share/doc/skf/copyright

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
