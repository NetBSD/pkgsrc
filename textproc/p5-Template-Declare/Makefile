# $NetBSD: Makefile,v 1.21 2017/06/05 14:24:47 ryoon Exp $

DISTNAME=	Template-Declare-0.47
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Declare/
COMMENT=	Perl 5 module to make Perlish declarative templates
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Template/Declare/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-ISA-[0-9]*:../../devel/p5-Class-ISA
DEPENDS+=	p5-String-BufferStack>=1.1:../../textproc/p5-String-BufferStack

BUILD_DEPENDS+=	p5-HTML-Lint-[0-9]*:../../www/p5-HTML-Lint
BUILD_DEPENDS+=	p5-Test-Warn>=0.11:../../devel/p5-Test-Warn

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
