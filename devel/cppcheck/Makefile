# $NetBSD: Makefile,v 1.15 2012/09/07 19:16:21 adam Exp $
#

DISTNAME=	cppcheck-1.48
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppcheck/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://cppcheck.wiki.sourceforge.net/
COMMENT=	Tool for static C/C++ code analysis
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c c++
USE_CMAKE=		yes
USE_TOOLS+=		gmake

BUILDLINK_TRANSFORM+=	rm:-Wlogical-op

.include "options.mk"

.PHONY: man-build
post-build: man-build
man-build:
	cd ${WRKSRC}/man && xsltproc --nonet \
		--param man.charmap.use.subset "0" \
		--param make.year.ranges "1" \
		--param make.single.year.ranges "1" \
		${PREFIX}/share/xsl/docbook/manpages/docbook.xsl \
		cppcheck.1.xml

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
