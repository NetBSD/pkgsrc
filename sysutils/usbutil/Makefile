# $NetBSD: Makefile,v 1.14 2008/11/25 13:22:30 bjs Exp $
#

DISTNAME=	usbutil-0.5
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.augustsson.net/pub/netbsd/

MAINTAINER=	lennart@augustsson.net
COMMENT=	USB developer utilities

PKG_DESTDIR_SUPPORT=	user-destdir

AUTO_MKDIRS=		yes
USE_BSD_MAKEFILE=	yes

INSTALL_TARGET+=	maninstall install

MAKE_FLAGS+=	BINDIR=${PREFIX:Q}/sbin
MAKE_FLAGS+=	MKCATPAGES=no
MAKE_FLAGS+=	MKHTML=no
MAKE_FLAGS+=	NOGCCERROR=yes	# in keeping with original Makefile

post-extract:
	${RUN} ${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
