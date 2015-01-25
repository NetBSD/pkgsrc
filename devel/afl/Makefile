# $NetBSD: Makefile,v 1.11 2015/01/25 19:11:10 wiz Exp $

DISTNAME=	afl-1.26b
CATEGORIES=	devel
MASTER_SITES=	http://lcamtuf.coredump.cx/afl/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lcamtuf.coredump.cx/afl/
COMMENT=	American Fuzzy Lop, a fuzzing tool for finding bugs by random input
LICENSE=	apache-2.0

USE_TOOLS+=	gmake
REPLACE_SH=	afl-plot afl-cmin

.include "../../mk/bsd.pkg.mk"
