# $NetBSD: Makefile,v 1.16 2019/08/11 13:21:59 wiz Exp $

DISTNAME=	Vroom-0.37
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IN/INGY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Vroom
COMMENT=	Slide Shows in Vim
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Vroom/.packlist

REPLACE_PERL+=	bin/vroom

DEPENDS+=	p5-Class-Field-[0-9]*:../../devel/p5-Class-Field
DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-IO-All-[0-9]*:../../devel/p5-IO-All
DEPENDS+=	p5-Template-Toolkit-Simple-[0-9]*:../../www/p5-Template-Toolkit-Simple
DEPENDS+=	p5-YAML-LibYAML-[0-9]*:../../textproc/p5-YAML-LibYAML
DEPENDS+=	p5-Term-Size-[0-9]*:../../devel/p5-Term-Size

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
