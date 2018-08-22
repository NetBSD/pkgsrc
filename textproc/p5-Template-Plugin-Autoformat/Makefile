# $NetBSD: Makefile,v 1.12 2018/08/22 09:46:57 wiz Exp $

DISTNAME=	Template-Plugin-Autoformat-2.77
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Plugin-Autoformat/
COMMENT=	Interface to Text::Autoformat module for TT2
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-Template-Toolkit<=2.21

DEPENDS+=	p5-Template-Toolkit>=2.02:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-Autoformat>=1.013:../../textproc/p5-Text-Autoformat

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Template/Plugin/Autoformat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
