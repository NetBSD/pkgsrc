# $NetBSD: Makefile,v 1.65 2020/08/01 14:31:52 wiz Exp $

DISTNAME=	afl-2.57b
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lcamtuf.coredump.cx/afl/
COMMENT=	American Fuzzy Lop, a fuzzing tool for finding bugs by random input
LICENSE=	apache-2.0

USE_TOOLS+=	bash:run gmake
REPLACE_SH+=	afl-plot
REPLACE_BASH+=	afl-cmin

WRKSRC=		${WRKDIR}/${PKGBASE:tu}-${PKGVERSION_NOREV}

.include "../../mk/bsd.pkg.mk"
