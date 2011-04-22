# $NetBSD: Makefile,v 1.22 2011/04/22 13:41:56 obache Exp $

DISTNAME=	libspf_alt-0.4.0
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://libspf2.org/spf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libspf2.org/
COMMENT=	Sender Permitted Framework (SPF) library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-bind=${BUILDLINK_PREFIX.libbind}

CONFLICTS+=	libspf2-[0-9]*
CONFLICTS+=	p5-Mail-SPF-[0-9]*

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
