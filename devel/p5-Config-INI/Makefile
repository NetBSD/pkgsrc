# $NetBSD: Makefile,v 1.16 2018/08/22 09:43:47 wiz Exp $

DISTNAME=	Config-INI-0.025
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-INI/
COMMENT=	Perl 5 module to handle simple .ini-file format
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Mixin-Linewise>=0.105:../../devel/p5-Mixin-Linewise

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Config/INI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
