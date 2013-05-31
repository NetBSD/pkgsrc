# $NetBSD: Makefile,v 1.8 2013/05/31 12:41:57 wiz Exp $

DISTNAME=	Text-Password-Pronounceable-0.30
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
PKGREVISION=	4
CATEGORIES=	perl5 textproc security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Password-Pronounceable/
COMMENT=	Generate pronounceable passwords
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Text/Password/Pronounceable/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
