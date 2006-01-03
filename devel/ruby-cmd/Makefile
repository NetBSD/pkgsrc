# $NetBSD: Makefile,v 1.6 2006/01/03 14:57:52 taca Exp $

DISTNAME=	cmd-0.7.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/3939/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/cmd/
COMMENT=	Library for building line-oriented command interpreters

DEPENDS+=	${RUBY_PKGPREFIX}-readline-[0-9]*:../../devel/ruby-readline

USE_RUBY_SETUP=	yes

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/cmd
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/cmd

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
