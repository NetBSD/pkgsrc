# $NetBSD: Makefile,v 1.9 2025/07/03 06:28:31 wiz Exp $

DISTNAME=	google-protobuf-4.31.1
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
