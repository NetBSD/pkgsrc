# $NetBSD: Makefile,v 1.5 2020/01/18 21:50:17 jperkin Exp $

DISTNAME=	libasr-1.0.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://www.opensmtpd.org/archives/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenSMTPD/libasr
COMMENT=	Asynchronous DNS resolver library
LICENSE=	isc AND modified-bsd AND 2-clause-bsd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-mantype=man

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
