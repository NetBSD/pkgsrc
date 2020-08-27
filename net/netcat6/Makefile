# $NetBSD: Makefile,v 1.12 2020/08/27 14:24:08 uwe Exp $

DISTNAME=		nc6-1.0
PKGNAME=		${DISTNAME:S/nc/netcat/}
PKGREVISION=		5
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.deepspace6.net/pub/ds6/sources/nc6/
MASTER_SITES+=		http://ftp.deepspace6.net/pub/ds6/sources/nc6/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.deepspace6.net/projects/netcat6.html
COMMENT=		Network swiss army knife
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

# don't auto-detect IPv6, use options.mk:
CONFIGURE_ARGS+=	--disable-stack-guess

USE_PKGLOCALEDIR=	yes
USE_FEATURES+=		inet6

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
