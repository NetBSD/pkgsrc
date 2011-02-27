# $NetBSD: Makefile,v 1.20 2011/02/27 12:48:05 obache Exp $

DISTNAME=	libspf_alt-0.4.0
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://libspf2.org/spf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libspf2.org/
COMMENT=	Sender Permitted Framework (SPF) library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-bind=${BUILDLINK_PREFIX.libbind}

CONFLICTS+=	libspf2-*

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
