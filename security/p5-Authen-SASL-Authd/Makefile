# $NetBSD: Makefile,v 1.7 2019/08/11 13:22:49 wiz Exp $
#

DISTNAME=	Authen-SASL-Authd-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Authen-SASL-Authd
COMMENT=	Perl module to handle SASL auth via Cyrus saslauthd or Dovecot
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Authen/SASL/Authd/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
