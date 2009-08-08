# $NetBSD: Makefile,v 1.1.1.1 2009/08/08 19:04:48 sno Exp $

DISTNAME=	TryCatch-1.001001
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sto
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AS/ASH/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/TryCatch/
COMMENT=	First class try catch semantics for Perl, without source filters
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Parse-Method-Signatures>=1.003003:../../devel/p5-Parse-Method-Signatures
DEPENDS+=	p5-B-Hooks-EndOfScope>=0.05:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=	p5-B-Hooks-OP-Check>=0.15:../../devel/p5-B-Hooks-OP-Check
DEPENDS+=	p5-B-Hooks-OP-PPAddr>=0.02:../../devel/p5-B-Hooks-OP-PPAddr
DEPENDS+=	p5-Devel-Declare>=0.003004:../../devel/p5-Devel-Declare
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
DEPENDS+=	p5-Scope-Upper>=0.06:../../devel/p5-Scope-Upper
DEPENDS+=	p5-Variable-Magic>=0.28:../../devel/p5-Variable-Magic
DEPENDS+=	p5-Sub-Exporter>=0.979:../../devel/p5-Sub-Exporter

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/TryCatch/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
