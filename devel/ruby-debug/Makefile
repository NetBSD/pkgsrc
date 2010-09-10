# $NetBSD: Makefile,v 1.5 2010/09/10 05:19:13 taca Exp $

DISTNAME=	ruby-debug-0.10.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-debug/
COMMENT=	Command line interface for ruby-debug
LICENSE=	2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-columnize>=0.1:../../misc/ruby-columnize
DEPENDS+=	${RUBY_PKGPREFIX}-debug-base>=0.10.3:../../devel/ruby-debug-base

RUBY_VERSION_SUPPORTED= 18

pre-configure:
	cd ${WRKSRC}/cli/ruby-debug/commands && \
		${MV} disassemble.RB disassemble.rb; \
		${MV} source.RB source.rb; \
		${RM} -f continue.RB.save

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
