# $NetBSD: Makefile,v 1.54 2023/04/14 04:32:44 wiz Exp $

DISTNAME=	psutils-2.10
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=rrthomas/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rrthomas/psutils/
COMMENT=	Utilities for manipulating PostScript documents
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl:run bash:test
TEST_TARGET=	check
REPLACE_BASH+=	tests/run-test

.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
