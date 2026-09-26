# $NetBSD: Makefile,v 1.25 2026/09/26 07:38:08 wiz Exp $

DISTNAME=	google-protobuf-4.36.2
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
