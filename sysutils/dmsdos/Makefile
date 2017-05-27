# $NetBSD: Makefile,v 1.4 2017/05/27 22:16:46 mef Exp $
#

DISTNAME=	dmsdos-0.9.2.3-pre2-alt2
PKGNAME=	dmsdos-0.9.2.3pre2alt2
CATEGORIES=	sysutils
MASTER_SITES=	http://cmp.felk.cvut.cz/~pisa/dmsdos/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cmp.felk.cvut.cz/~pisa/dmsdos/
COMMENT=	Program to access DBLSPACE/DRVSPACE containers
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/dmsdos-0.9.2.3-pre2-alt2/src

F=	mcdmsdos.c dblspace_dec.c lib_interface.c dblspace_interface.c \
	dblspace_chk.c dblspace_tables.c dstacker_alloc.c dblspace_alloc.c \
	dblspace_compr.c dstacker_compr.c dstacker_dec.c dblspace_methsq.c

INSTALLATION_DIRS=	bin

do-configure:
	${CP} ${WRKSRC}/dmsdos-config.h.default ${WRKSRC}/dmsdos-config.h

do-build:
	cd ${WRKSRC} && ${CC} -D__DMSDOS_LIB__ ${F} -o mcdmsdos

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mcdmsdos ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
