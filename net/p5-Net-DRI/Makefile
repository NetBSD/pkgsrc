# $NetBSD: Makefile,v 1.2 2018/08/22 09:45:59 wiz Exp $

DISTNAME=	Net-DRI-0.96
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dotandco.com/services/software/Net-DRI/index.en
COMMENT=	Perl5 module to access DNS registries/registrars w/EPP
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Strptime-[0-9]*:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-DateTime-Format-ISO8601>=0.06:../../time/p5-DateTime-Format-ISO8601
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Accessor-Chained-[0-9]*:../../devel/p5-Class-Accessor-Chained
DEPENDS+=	p5-IO-Socket-SSL>=1.31:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Email-Valid-[0-9]*:../../mail/p5-Email-Valid
DEPENDS+=	p5-XML-LibXML>=1.61:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-Module-Load-[0-9]*:../../devel/p5-Module-Load
DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

PERL5_PACKLIST=	auto/Net/DRI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
