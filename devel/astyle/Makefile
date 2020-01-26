# $NetBSD: Makefile,v 1.23 2020/01/26 05:26:22 rillig Exp $

DISTNAME=	astyle_3.1_linux
PKGNAME=	${DISTNAME:S/_linux//:S/_/-/}
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=astyle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://astyle.sourceforge.net/
COMMENT=	Free, Fast and Small Automatic Formatter for C, C++, C++/CLI, C\#, and Java
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/astyle
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
BUILD_DIRS=	build/mac
.else
BUILD_DIRS=	build/gcc
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_DIRS}/bin/astyle ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${DESTDIR}${PREFIX}/share/doc/astyle

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
