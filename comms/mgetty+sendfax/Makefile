# $NetBSD: Makefile,v 1.9 2000/05/17 03:43:48 fredb Exp $
# FreeBSD Id: Makefile,v 1.25 1998/07/16 06:44:37 vanilla Exp
#

DISTNAME=	mgetty1.1.21-Jul24
PKGNAME=	mgetty-1.1.21
CATEGORIES=	comms
MASTER_SITES=	ftp://alpha.greenie.net/pub/mgetty/source/1.1/

PATCH_SITES=	http://www-internal.alphanet.ch/~schaefer/vgetty/global_patches/CURRENT/
PATCHFILES=	mgetty-1.1.21-to-current.bz2
PATCH_DIST_STRIP= -p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://alpha.greenie.net/mgetty/

CONFLICTS=	hylafax-*

WRKSRC=		${WRKDIR}/${PKGNAME}
INFO_FILES=	mgetty.info

post-configure:
	@cd ${WRKSRC}; \
	${MV} faxrunq.config faxrunq.config.old; \
	${SED} -e 's#/usr/local#${PREFIX}#' <faxrunq.config.old >faxrunq.config

pre-install:
	@(cd ${WRKSRC}/doc; ${MAKE} manpages)

.include "../../mk/bsd.pkg.mk"
