# $NetBSD: Makefile,v 1.2 2020/01/18 23:35:24 rillig Exp $

DISTNAME=	csvutils-0.9.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=csvutils/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://csvutils.sourceforge.net/
COMMENT=	Command-line utilities for managing CSV data using libcsv
LICENSE=	gnu-gpl-v2

CONFLICTS=	csvkit-[0-9]*

USE_TOOLS+=	gmake gunzip

MAKE_ENV+=	INCLUDES="-I${PREFIX}/include" PREFIX="${PREFIX}" MANDIR="${PKGMANDIR}"
MAKE_ENV+=	LDFLAGS="-R,-L${PREFIX}/lib"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

pre-install:
	set -e ; \
	for f in ${WRKSRC}/*.gz; do \
		gunzip "$${f}" ; \
	done

.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libcsv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
