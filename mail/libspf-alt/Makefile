# $NetBSD: Makefile,v 1.1.1.1 2004/04/14 14:44:08 manu Exp $
#

DISTNAME=	libspf_alt-0.4.0
CATEGORIES=	mail
MASTER_SITES=	http://www.midwestcs.com/spf/libspf-alt/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.midwestcs.com/spf/libspf-alt/
COMMENT=	Sender Permitted Framework (SPF) library

DEPENDS+=	bind>=9.2.3nb3:../../net/bind9

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-bind=${PREFIX} --prefix=${PREFIX}

.include "../../net/bind9/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
