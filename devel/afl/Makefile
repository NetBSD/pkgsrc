# $NetBSD: Makefile,v 1.36 2016/03/08 14:41:55 wiz Exp $

DISTNAME=	afl-2.06b
CATEGORIES=	devel
MASTER_SITES=	http://lcamtuf.coredump.cx/afl/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lcamtuf.coredump.cx/afl/
COMMENT=	American Fuzzy Lop, a fuzzing tool for finding bugs by random input
LICENSE=	apache-2.0

USE_TOOLS+=	bash:run gmake
REPLACE_SH+=	afl-plot
REPLACE_BASH+=	afl-cmin

.include "../../mk/bsd.pkg.mk"
