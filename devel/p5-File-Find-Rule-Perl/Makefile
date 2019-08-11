# $NetBSD: Makefile,v 1.21 2019/08/11 13:19:26 wiz Exp $

DISTNAME=	File-Find-Rule-Perl-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Find-Rule-Perl
COMMENT=	Common File::Find::Rule rules for searching for Perl things
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Find-Rule>=0.20:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-Params-Util>=0.38:../../devel/p5-Params-Util
#DEPENDS+=	{perl>=5.10.1,p5-Parse-CPAN-Meta>=1.38}:../../devel/p5-Parse-CPAN-Meta

PERL5_PACKLIST=		auto/File/Find/Rule/Perl/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
