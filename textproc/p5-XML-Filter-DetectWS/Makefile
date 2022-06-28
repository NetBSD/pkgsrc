# $NetBSD: Makefile,v 1.26 2022/06/28 11:36:41 wiz Exp $

DISTNAME=	XML-Filter-DetectWS-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TJ/TJMATHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/TJMATHER/XML-Filter-DetectWS-0.01
COMMENT=	PerlSAX filter that detects ignorable whitespace

CONFLICTS+=	p5-libxml-enno-[0-9]*

DEPENDS+=	p5-XML-Filter-SAXT>=0.01:../../textproc/p5-XML-Filter-SAXT

PERL5_PACKLIST=	auto/XML/Filter/DetectWS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
