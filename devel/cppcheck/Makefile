# $NetBSD: Makefile,v 1.69 2020/06/23 20:46:50 wiz Exp $

DISTNAME=	cppcheck-1.90
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppcheck/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://cppcheck.sourceforge.net/
COMMENT=	Tool for static C/C++ code analysis
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

USE_LANGUAGES=		c c++0x
USE_TOOLS+=		gmake

BUILD_TARGET=		all man
BUILD_MAKE_FLAGS+=	DB2MAN=${PREFIX}/share/xsl/docbook/manpages/docbook.xsl
# tell cppcheck where its CPP files are
MAKE_FLAGS+=		FILESDIR=${PREFIX}/share/cppcheck
# rules support (needs pcre)
MAKE_FLAGS+=		HAVE_RULES=yes

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.[0-5]*) || !empty(CC_VERSION:Mgcc-3.*)
CXXFLAGS+= -include lib/cxx11emu.h
.endif

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

REPLACE_PYTHON+=	htmlreport/cppcheck-htmlreport

.include "options.mk"

.PHONY: man-install
post-install: man-install
man-install:
	${INSTALL_DATA} ${WRKSRC}/cppcheck.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
