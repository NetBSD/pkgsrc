# $NetBSD: Makefile,v 1.8 2012/05/06 10:12:20 wiz Exp $

DISTNAME=	thrift-0.7.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://thrift.apache.org/
COMMENT=	Ruby libraries for Thrift (a language-agnostic RPC system)
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/libthrift/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
