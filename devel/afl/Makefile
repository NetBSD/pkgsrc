# $NetBSD: Makefile,v 1.34 2016/02/21 10:35:37 wiz Exp $

DISTNAME=	afl-2.03b
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
