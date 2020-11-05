# $NetBSD: Makefile,v 1.14 2020/11/05 09:07:52 ryoon Exp $

DISTNAME=	creduce-2.10.0
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	https://embed.cs.utah.edu/creduce/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://embed.cs.utah.edu/creduce/
COMMENT=	Tool for automatic reduction of C/C++ files triggering bugs
LICENSE=	2-clause-bsd

DEPENDS+=	p5-Exporter-Lite-[0-9]*:../../devel/p5-Exporter-Lite
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-Getopt-Tabular-[0-9]*:../../devel/p5-Getopt-Tabular
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Sys-CPU-[0-9]*:../../sysutils/p5-Sys-CPU
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common

USE_LANGUAGES=	c c++14
USE_TOOLS+=	flex perl:run gmake
GNU_CONFIGURE=	yes
TEST_TARGET=	check

.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
