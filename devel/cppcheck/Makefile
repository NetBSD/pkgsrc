# $NetBSD: Makefile,v 1.31 2015/01/14 21:48:10 wiz Exp $

DISTNAME=	cppcheck-1.68
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppcheck/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://cppcheck.wiki.sourceforge.net/
COMMENT=	Tool for static C/C++ code analysis
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

FIND_PREFIX:=	DBXSLDIR=docbook-xsl
.include "../../mk/find-prefix.mk"

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
BUILD_TARGET=		all man
BUILD_MAKE_FLAGS+=	DB2MAN=${DBXSLDIR}/share/xsl/docbook/manpages/docbook.xsl
# tell cppcheck where its config is
MAKE_FLAGS+=		CFGDIR=${PREFIX}/share/cppcheck/cfg
# rules support (needs pcre)
MAKE_FLAGS+=		HAVE_RULES=yes

# use pkgsrc tinyxml2 instead of included copy
MAKE_FLAGS+=		TINYXML=
CPPFLAGS+=		-I${BUILDLINK_PREFIX.tinyxml2}/include
LDFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.tinyxml2}/lib -L${BUILDLINK_PREFIX.tinyxml2}/lib -ltinyxml2

# http://5.150.254.56:443/trac-cppcheck/ticket/6026#ticket
.include "../../mk/bsd.fast.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-6].*-*) || empty(MACHINE_PLATFORM:MNetBSD-*)
# no backtrace() on NetBSD<7 (6.99.8 actually); add other systems with backtrace() when you find them
CPPFLAGS+=		-DNO_UNIX_BACKTRACE_SUPPORT=1
.else
LDFLAGS+=		-lexecinfo
.endif

INSTALLATION_DIRS=	${PKGMANDIR}/man1

REPLACE_PYTHON+=	htmlreport/cppcheck-htmlreport

.include "options.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/cppcheck.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.if !empty(PKG_OPTIONS:Mqt)
	${INSTALL_PROGRAM} ${WRKSRC}/gui/cppcheck-gui \
		${DESTDIR}${PREFIX}/bin
.endif

.include "../../lang/python/application.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/tinyxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
