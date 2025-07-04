# $NetBSD: Makefile,v 1.23 2025/07/04 08:48:05 wiz Exp $

DISTNAME=	Text-Password-Pronounceable-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	perl5 textproc security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Password-Pronounceable
COMMENT=	Generate pronounceable passwords
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Password/Pronounceable/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
