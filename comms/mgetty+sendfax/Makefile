# $NetBSD: Makefile,v 1.3 1998/11/15 20:55:56 tron Exp $
# FreeBSD Id: Makefile,v 1.25 1998/07/16 06:44:37 vanilla Exp
#

DISTNAME=	mgetty1.1.16-Jul05
PKGNAME=	mgetty-1.1.16
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/os/unix/networking/mgetty/ \
		ftp://ftp.nlc.net.au/pub/unix/net/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.leo.org/~doering/mgetty/index.html

WRKSRC=		${WRKDIR}/mgetty-1.1.16
INFO_FILES=	mgetty.info

post-configure:
	@cd ${WRKSRC}; \
	${MV} faxrunq.config faxrunq.config.old; \
	${SED} -e 's#/usr/local#${PREFIX}#' <faxrunq.config.old >faxrunq.config

pre-install:
	@(cd ${WRKSRC}/doc; ${MAKE} manpages)

.include <../../mk/bsd.pkg.mk>
