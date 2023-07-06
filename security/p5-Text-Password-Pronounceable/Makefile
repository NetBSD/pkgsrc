# $NetBSD: Makefile,v 1.21 2023/07/06 09:41:29 wiz Exp $

DISTNAME=	Text-Password-Pronounceable-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
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
