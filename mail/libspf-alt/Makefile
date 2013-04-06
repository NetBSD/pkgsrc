# $NetBSD: Makefile,v 1.24 2013/04/06 14:22:40 rodent Exp $

DISTNAME=	libspf_alt-0.4.0
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://libspf2.org/spf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libspf2.org/
COMMENT=	Sender Permitted Framework (SPF) library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--with-bind=${BUILDLINK_PREFIX.libbind}

CONFLICTS+=	libspf2-[0-9]*
CONFLICTS+=	p5-Mail-SPF-[0-9]*

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
