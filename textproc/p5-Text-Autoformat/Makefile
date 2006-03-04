# $NetBSD: Makefile,v 1.14 2006/03/04 21:30:48 jlam Exp $

DISTNAME=	Text-Autoformat-1.13
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tau
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Autoformat/
COMMENT=	Perl module for text wrapping and reformatting

DEPENDS+=	p5-Text-Reform>=1.11:../../textproc/p5-Text-Reform

PERL5_PACKLIST=		auto/Text/Autoformat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
