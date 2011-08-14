# $NetBSD: Makefile,v 1.25 2011/08/14 12:26:19 obache Exp $
#

DISTNAME=	Module-ScanDeps-0.98
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5msd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-ScanDeps/
COMMENT=	Perl 5 module to recursively scan Perl code for dependencies
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/ScanDeps/.packlist
#PERL5_MODULE_TYPE=	Module::Install
MAKE_PARAMS+=		--skipdeps

REPLACE_PERL+=	script/scandeps.pl

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
