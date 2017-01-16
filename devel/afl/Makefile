# $NetBSD: Makefile,v 1.53 2017/01/16 09:17:19 wiz Exp $

DISTNAME=	afl-2.36b
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
