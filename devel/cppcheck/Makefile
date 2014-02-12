# $NetBSD: Makefile,v 1.29 2014/02/12 23:17:45 tron Exp $

DISTNAME=	cppcheck-1.60.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppcheck/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://cppcheck.wiki.sourceforge.net/
COMMENT=	Tool for static C/C++ code analysis
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

FIND_PREFIX:=	DBXSLDIR=docbook-xsl
.include "../../mk/find-prefix.mk"

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
BUILD_TARGET=		all man
BUILD_MAKE_FLAGS+=	DB2MAN=${DBXSLDIR}/share/xsl/docbook/manpages/docbook.xsl
INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "options.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/cppcheck.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.if !empty(PKG_OPTIONS:Mqt)
	${INSTALL_PROGRAM} ${WRKSRC}/gui/cppcheck-gui \
		${DESTDIR}${PREFIX}/bin
.endif

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
