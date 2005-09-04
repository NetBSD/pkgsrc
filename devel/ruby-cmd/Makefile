# $NetBSD: Makefile,v 1.3 2005/09/04 13:53:53 taca Exp $

DISTNAME=	cmd-0.7.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://code.vernix.org/cmd/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://cmd.rubyforge.org/
COMMENT=	Library for building line-oriented command interpreters

DEPENDS+=	${RUBY_PKGPREFIX}-readline-[0-9]*:../../devel/ruby-readline

USE_RUBY_SETUP=	yes

.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/cmd
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/cmd

.include "../../mk/bsd.pkg.mk"
