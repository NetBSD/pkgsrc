# $NetBSD: Makefile,v 1.23 2012/10/08 12:19:15 asau Exp $

DISTNAME=	libspf_alt-0.4.0
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://libspf2.org/spf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libspf2.org/
COMMENT=	Sender Permitted Framework (SPF) library

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-bind=${BUILDLINK_PREFIX.libbind}

CONFLICTS+=	libspf2-[0-9]*
CONFLICTS+=	p5-Mail-SPF-[0-9]*

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
