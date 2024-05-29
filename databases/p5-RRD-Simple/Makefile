# $NetBSD: Makefile,v 1.64 2024/05/29 16:31:45 adam Exp $

DISTNAME=	RRD-Simple-1.44
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	56
CATEGORIES=	perl5 databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RRD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/RRD-Simple
COMMENT=	RRD::Simple implementation for Perl
LICENSE=	apache-2.0

TOOL_DEPENDS+=	p5-Test-Pod>=1.26:../../devel/p5-Test-Pod
TOOL_DEPENDS+=	p5-Pod-Coverage>=0.18:../../textproc/p5-Pod-Coverage
TOOL_DEPENDS+=	p5-Test-Pod-Coverage>=1.08:../../devel/p5-Test-Pod-Coverage
TOOL_DEPENDS+=	p5-Test-Deep>=0.096:../../devel/p5-Test-Deep

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/RRD/Simple/.packlist
MAKE_PARAMS+=		< /dev/null

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
