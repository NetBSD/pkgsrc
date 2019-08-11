# $NetBSD: Makefile,v 1.24 2019/08/11 13:22:20 wiz Exp $

DISTNAME=	Net-Jifty-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Jifty
COMMENT=	Interface to online Jifty applications
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Email-Address-[0-9]*:../../mail/p5-Email-Address
#DEPENDS+=	{perl>=5.7.3,p5-Encode-[0-9]*}:../../textproc/p5-Encode
DEPENDS+=	p5-Hash-Merge-[0-9]*:../../devel/p5-Hash-Merge
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Any-Moose>=0.04:../../devel/p5-Any-Moose
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-Test-MockObject-[0-9]*:../../devel/p5-Test-MockObject
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Net/Jifty/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
