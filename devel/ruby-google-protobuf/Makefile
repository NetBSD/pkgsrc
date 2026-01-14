# $NetBSD: Makefile,v 1.14 2026/01/14 12:57:33 wiz Exp $

DISTNAME=	google-protobuf-4.33.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.google.com/protocol-buffers
COMMENT=	Protocol Buffers functionality in Ruby
LICENSE=	modified-bsd

pre-configure:
	cd ${WRKSRC} && ${FIND} . -type f -exec chmod -x {} \;

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
