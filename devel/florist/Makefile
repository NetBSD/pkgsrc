# $NetBSD: Makefile,v 1.20 2018/04/02 09:30:06 wiz Exp $

DISTNAME=		florist-gpl-2012-src
PKGNAME=		florist-gpl-2012
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://downloads.dragonlace.net/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://libre.adacore.com/
COMMENT=		POSIX Ada Binding, IEEE Standards 1003.5(b,c)
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c ada

post-extract:
	${CP} ${FILESDIR}/pconfig.* ${WRKSRC}/configs

.include "../../mk/bsd.pkg.mk"
