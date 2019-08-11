# $NetBSD: Makefile,v 1.20 2019/08/11 13:19:44 wiz Exp $

DISTNAME=	Log-Any-Adapter-Log4perl-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Any-Adapter-Log4perl
COMMENT=	Adapter to use Log::Log4perl with Log::Any
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Any-[0-9]*:../../devel/p5-Log-Any
DEPENDS+=	p5-Log-Log4perl>=1.32:../../devel/p5-Log-Log4perl

PERL5_PACKLIST=		auto/Log/Any/Adapter/Log4perl/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
