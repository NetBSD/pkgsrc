# $NetBSD: Makefile,v 1.31 2020/08/31 18:12:09 wiz Exp $

DISTNAME=	XML-Encoding-2.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Encoding
COMMENT=	Perl module for parsing XML encoding maps
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-Parser>=2.18:../../textproc/p5-XML-Parser

PERL5_PACKLIST=	auto/XML/Encoding/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
