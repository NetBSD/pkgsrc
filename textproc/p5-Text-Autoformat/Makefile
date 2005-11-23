# $NetBSD: Makefile,v 1.13 2005/11/23 22:14:52 wiz Exp $

DISTNAME=	Text-Autoformat-1.13
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tau
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Autoformat/
COMMENT=	Perl module for text wrapping and reformatting

DEPENDS+=	p5-Text-Reform>=1.11:../../textproc/p5-Text-Reform

PERL5_PACKLIST=		auto/Text/Autoformat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
