# $NetBSD: Makefile,v 1.13 2016/06/08 19:24:40 wiz Exp $
#

DISTNAME=	Text-Unaccent-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Unaccent/
COMMENT=	Perl5 module that removes accents from a string

PERL5_PACKLIST=		auto/Text/Unaccent/.packlist

# needs iconv(1)
.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
