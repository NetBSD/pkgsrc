# $NetBSD: Makefile,v 1.5 2004/04/15 20:27:18 tron Exp $

DISTNAME=	libspf_alt-0.4.0
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.midwestcs.com/spf/libspf-alt/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.midwestcs.com/spf/libspf-alt/
COMMENT=	Sender Permitted Framework (SPF) library

DEPENDS+=	bind>=9.2.3nb3:../../net/bind9

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-bind=${BUILDLINK_PREFIX.bind} --prefix=${PREFIX}

.include "../../net/bind9/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
