# $NetBSD: Makefile,v 1.1 2016/11/02 00:15:43 joerg Exp $

DISTNAME=	creduce-2.5.0
CATEGORIES=	devel
MASTER_SITES=	https://embed.cs.utah.edu/creduce/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://embed.cs.utah.edu/creduce/
COMMENT=	Tool for automatic reduction of C/C++ files triggering bugs
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

USE_TOOLS+=	flex perl:run gmake
USE_LANGUAGES=	c c++

DEPENDS+=	p5-Exporter-Lite-[0-9]*:../../devel/p5-Exporter-Lite
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-Getopt-Tabular-[0-9]*:../../devel/p5-Getopt-Tabular
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Sys-CPU-[0-9]*:../../sysutils/p5-Sys-CPU
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common

.include "../../mk/bsd.prefs.mk"

CXXFLAGS+=	-std=c++11

.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
