# $NetBSD: Makefile,v 1.19 2011/02/27 12:37:24 obache Exp $

DISTNAME=	libspf_alt-0.4.0
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://libspf2.org/spf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libspf2.org/
COMMENT=	Sender Permitted Framework (SPF) library

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.bind+=	bind>=9.2.3nb3

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-bind=${BUILDLINK_PREFIX.bind}

CONFLICTS+=	libspf2-*

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
