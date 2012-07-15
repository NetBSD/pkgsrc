# $NetBSD: Makefile,v 1.15 2012/07/15 11:52:57 marino Exp $
#

DISTNAME=		florist-gpl-2012-src
PKGNAME=		florist-gpl-2012
CATEGORIES=		devel
MASTER_SITES=		http://downloads.dragonlace.net/src/ \
			http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		draco@marino.st
HOMEPAGE=		http://libre.adacore.com/
COMMENT=		POSIX Ada Binding, IEEE Standards 1003.5(b,c)
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c ada

post-extract:
	${CP} ${FILESDIR}/pconfig.* ${WRKSRC}/configs

.include "../../mk/bsd.pkg.mk"
