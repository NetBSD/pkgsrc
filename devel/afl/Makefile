# $NetBSD: Makefile,v 1.66 2021/06/24 19:00:32 rillig Exp $

DISTNAME=	afl-2.57b
PKGREVISION=	1
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

# docs/README is empty; fixed upstream after 2.57b
post-build:
	cp ${WRKSRC}/README.md ${WRKSRC}/docs/README

.include "../../mk/bsd.pkg.mk"
