# $NetBSD: Makefile,v 1.18 2026/03/29 07:25:39 taca Exp $

DISTNAME=	google-protobuf-4.34.1
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
