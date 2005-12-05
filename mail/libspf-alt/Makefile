# $NetBSD: Makefile,v 1.10 2005/12/05 23:55:11 rillig Exp $

DISTNAME=	libspf_alt-0.4.0
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.midwestcs.com/spf/libspf-alt/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.midwestcs.com/spf/libspf-alt/
COMMENT=	Sender Permitted Framework (SPF) library

BUILDLINK_DEPENDS.bind+=	bind>=9.2.3nb3

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-bind=${BUILDLINK_PREFIX.bind} --prefix=${PREFIX:Q}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/bind9/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
