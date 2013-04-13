# $NetBSD: Makefile,v 1.9 2013/04/13 07:55:02 ghen Exp $

DISTNAME=		nc6-1.0
PKGNAME=		${DISTNAME:S/nc/netcat/}
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.deepspace6.net/pub/ds6/sources/nc6/
MASTER_SITES+=		http://ftp.deepspace6.net/pub/ds6/sources/nc6/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Network swiss army knife
HOMEPAGE=		http://www.deepspace6.net/projects/netcat6.html

GNU_CONFIGURE=		yes

# don't auto-detect IPv6, use options.mk:
CONFIGURE_ARGS+=	--disable-stack-guess

USE_PKGLOCALEDIR=	yes
USE_FEATURES+=		inet6

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
