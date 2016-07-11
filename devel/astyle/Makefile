# $NetBSD: Makefile,v 1.18 2016/07/11 18:26:52 schmonz Exp $

DISTNAME=	astyle_2.05.1_linux
PKGNAME=	${DISTNAME:S/_linux//:S/_/-/}
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=astyle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://astyle.sourceforge.net/
COMMENT=	Free, Fast and Small Automatic Formatter for C, C++, C++/CLI, C#, and Java
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/astyle
BUILD_DIRS=	build/gcc
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

HTMLDIR=	${PREFIX}/share/doc/html/astyle
INSTALLATION_DIRS=	bin ${HTMLDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/gcc/bin/astyle ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${DESTDIR}${HTMLDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
