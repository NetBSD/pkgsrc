# $NetBSD: Makefile,v 1.25 2014/10/12 08:17:50 tron Exp $

DISTNAME=	libspf_alt-0.4.0
PKGREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	http://libspf2.org/spf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libspf2.org/
COMMENT=	Sender Permitted Framework (SPF) library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--with-bind=${BUILDLINK_PREFIX.libbind}

CONFLICTS+=	libspf2-[0-9]*

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
