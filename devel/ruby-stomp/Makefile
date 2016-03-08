# $NetBSD: Makefile,v 1.8 2016/03/08 14:51:43 taca Exp $

DISTNAME=	stomp-1.3.5
CATEGORIES=	devel

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/stomp/
COMMENT=	Ruby library for the Stomp protocol
LICENSE=	apache-2.0

RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${CHMOD} +x ${WRKSRC}/bin/catstomp ${WRKSRC}/bin/stompcat

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
