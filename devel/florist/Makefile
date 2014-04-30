# $NetBSD: Makefile,v 1.17 2014/04/30 16:27:04 marino Exp $
#

DISTNAME=		florist-gpl-2012-src
PKGNAME=		florist-gpl-2012
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		draco@marino.st
HOMEPAGE=		http://libre.adacore.com/
COMMENT=		POSIX Ada Binding, IEEE Standards 1003.5(b,c)
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c ada

post-extract:
	${CP} ${FILESDIR}/pconfig.* ${WRKSRC}/configs

.include "../../mk/bsd.pkg.mk"
