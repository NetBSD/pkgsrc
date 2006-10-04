# $NetBSD: Makefile,v 1.14 2006/10/04 21:47:16 wiz Exp $

DISTNAME=	libspf_alt-0.4.0
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://libspf2.org/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://libspf2.org/
COMMENT=	Sender Permitted Framework (SPF) library

BUILDLINK_API_DEPENDS.bind+=	bind>=9.2.3nb3

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-bind=${BUILDLINK_PREFIX.bind}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/bind9/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
