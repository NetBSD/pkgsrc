# $NetBSD: Makefile,v 1.23 2013/05/31 12:41:53 wiz Exp $
#

DISTNAME=	Authen-SASL-2.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Authen-SASL/
COMMENT=	Perl module to handle SASL authentication
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Authen/SASL/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
# recommended
DEPENDS+=	p5-GSSAPI-[0-9]*:../../security/p5-GSSAPI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
