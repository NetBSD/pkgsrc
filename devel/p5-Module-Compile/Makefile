# $NetBSD: Makefile,v 1.1 2017/09/27 21:21:09 wiz Exp $

DISTNAME=	Module-Compile-0.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Compile
COMMENT=	Perl Module Compilation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1

#PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Compile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
