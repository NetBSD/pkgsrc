# $NetBSD: Makefile,v 1.3 2020/03/20 11:58:25 nia Exp $

DISTNAME=	csvutils-0.9.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=csvutils/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://csvutils.sourceforge.net/
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
