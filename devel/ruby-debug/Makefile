# $NetBSD: Makefile,v 1.10 2013/03/07 15:09:14 taca Exp $

DISTNAME=	ruby-debug-0.10.4
PKGREVISION=	3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-debug/
COMMENT=	Command line interface for ruby-debug
LICENSE=	2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-columnize>=0.1:../../misc/ruby-columnize
DEPENDS+=	${RUBY_PKGPREFIX}-debug-base>=0.10.4<0.10.5:../../devel/ruby-debug-base

RUBY_VERSION_SUPPORTED= 18

OVERRIDE_GEMSPEC= :files \
	cli/ruby-debug/processor.RB=cli/ruby-debug/processor.rb \
	cli/ruby-debug/commands/raise.RB=cli/ruby-debug/commands/raise.rb \
	cli/ruby-debug/commands/disassemble.RB= \
	cli/ruby-debug/commands/source.RB= \
	cli/ruby-debug/commands/continue.RB=cli/ruby-debug/commands/continue.rb

pre-configure:
	${RM} -f ${WRKSRC}/cli/ruby-debug/processor.RB
	${RM} -f ${WRKSRC}/cli/ruby-debug/disassemble.RB
	cd ${WRKSRC}/cli/ruby-debug/commands && \
		${MV} raise.RB raise.rb; \
		${MV} source.RB source.rb;
		${RM} -f continue.RB.save

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
