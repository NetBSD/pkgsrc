# $NetBSD: Makefile,v 1.14 2018/08/22 09:44:50 wiz Exp $
#

DISTNAME=	Test-Script-Run-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Script-Run/
COMMENT=	Perl 5 module to test scripts
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Test/Script/Run/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
