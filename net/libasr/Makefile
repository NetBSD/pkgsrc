# $NetBSD: Makefile,v 1.3 2018/07/31 07:04:29 wiz Exp $

DISTNAME=	libasr-1.0.2
CATEGORIES=	net
MASTER_SITES=	https://www.opensmtpd.org/archives/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenSMTPD/libasr
COMMENT=	Asynchronous DNS resolver library
LICENSE=	isc AND modified-bsd AND 2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--with-mantype=man

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
