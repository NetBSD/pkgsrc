# $NetBSD: Makefile,v 1.1 2016/05/01 05:03:23 mef Exp $

DISTNAME=	libasr-1.0.2
CATEGORIES=	net
MASTER_SITES=	http://www.opensmtpd.org/archives/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenSMTPD/libasr
COMMENT=	Asynchronous DNS resolver library
LICENSE=	isc AND modified-bsd AND 2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
