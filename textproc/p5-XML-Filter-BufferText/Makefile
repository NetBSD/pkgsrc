# $NetBSD: Makefile,v 1.27 2022/06/28 11:36:40 wiz Exp $

DISTNAME=	XML-Filter-BufferText-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Filter-BufferText
COMMENT=	Perl5 module XML parser filter to put all characters() in one event

DEPENDS+=	p5-XML-SAX>=0.04:../../textproc/p5-XML-SAX

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/XML/Filter/BufferText/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
