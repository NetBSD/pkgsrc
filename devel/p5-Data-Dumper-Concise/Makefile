# $NetBSD: Makefile,v 1.6 2011/08/11 17:20:00 adam Exp $

DISTNAME=	Data-Dumper-Concise-2.020
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Dumper-Concise/
COMMENT=	Perl 5 module to dump references with concision and deparsing
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

# XXX recommended: Devel::ArgNames - import

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Dumper/Concise/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
