# $NetBSD: Makefile,v 1.1.1.1 2005/04/11 03:26:55 minskim Exp $

DISTNAME=	cmd-0.7.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://code.vernix.org/cmd/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://code.vernix.org/cmd/download/
COMMENT=	Library for building  line-oriented command interpreters

DEPENDS+=	${RUBY_PKGPREFIX}-readline-[0-9]*:../../devel/ruby-readline

USE_RUBY_SETUP=	yes

.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/cmd
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/cmd

.include "../../mk/bsd.pkg.mk"
