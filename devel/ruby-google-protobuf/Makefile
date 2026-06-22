# $NetBSD: Makefile,v 1.20 2026/06/22 19:38:47 wiz Exp $

DISTNAME=	google-protobuf-4.35.0
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
