# $NetBSD: Makefile,v 1.8 2004/10/03 00:12:53 tv Exp $

DISTNAME=	libspf_alt-0.4.0
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.midwestcs.com/spf/libspf-alt/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.midwestcs.com/spf/libspf-alt/
COMMENT=	Sender Permitted Framework (SPF) library

BUILDLINK_DEPENDS.bind+=	bind>=9.2.3nb3

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-bind=${BUILDLINK_PREFIX.bind} --prefix=${PREFIX}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/bind9/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
