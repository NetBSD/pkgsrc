# $NetBSD: Makefile,v 1.15 2018/12/09 21:05:35 adam Exp $

DISTNAME=	Text-Password-Pronounceable-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	perl5 textproc security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Password-Pronounceable/
COMMENT=	Generate pronounceable passwords
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Password/Pronounceable/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
