# $NetBSD: Makefile,v 1.13 2000/10/21 22:19:21 wiz Exp $
# FreeBSD Id: Makefile,v 1.25 1998/07/16 06:44:37 vanilla Exp
#

DISTNAME=	mgetty1.1.22-Aug17
PKGNAME=	mgetty-1.1.22
CATEGORIES=	comms
MASTER_SITES=	ftp://alpha.greenie.net/pub/mgetty/source/1.1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://alpha.greenie.net/mgetty/

DEPENDS=	netpbm-[0-9]*:../../graphics/netpbm

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
