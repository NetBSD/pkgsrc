# $NetBSD: Makefile,v 1.1 2017/10/13 16:29:07 minskim Exp $

DISTNAME=	rex-ole-0.1.6
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-ole
COMMENT=	Rex Library for reading/writing OLE files and streams
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
