# $NetBSD: Makefile,v 1.1.1.1 2008/02/08 21:18:44 drochner Exp $
#

DISTNAME=	dmsdos-0.9.2.3-pre2
PKGNAME=	dmsdos-0.9.2.3pre2
CATEGORIES=	sysutils
MASTER_SITES=	http://cmp.felk.cvut.cz/~pisa/dmsdos/sources/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cmp.felk.cvut.cz/~pisa/dmsdos/
COMMENT=	Program to access DBLSPACE/DRVSPACE containers

WRKSRC=		${WRKDIR}/dmsdos-0.9.2.3-pre2/src

F=	mcdmsdos.c dblspace_dec.c lib_interface.c dblspace_interface.c \
	dblspace_chk.c dblspace_tables.c dstacker_alloc.c dblspace_alloc.c \
	dblspace_compr.c dstacker_compr.c dstacker_dec.c dblspace_methsq.c

post-extract:
	find ${WRKDIR}/dmsdos-0.9.2.3-pre2 -type d -exec chmod +x {} \;

do-configure:
	${CP} ${WRKSRC}/dmsdos-config.h.default ${WRKSRC}/dmsdos-config.h

do-build:
	cd ${WRKSRC} && ${CC} -D__DMSDOS_LIB__ ${F} -o mcdmsdos

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mcdmsdos ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
