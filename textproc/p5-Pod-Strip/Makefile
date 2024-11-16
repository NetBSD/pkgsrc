# $NetBSD: Makefile,v 1.22 2024/11/16 12:06:51 wiz Exp $
#

DISTNAME=	Pod-Strip-1.100
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Pod-Strip
COMMENT=	Perl5 module to remove POD from Perl code

PERL5_PACKLIST=		auto/Pod/Strip/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
