# $NetBSD: Makefile,v 1.23 2019/08/11 13:23:53 wiz Exp $

DISTNAME=	XML-Filter-SAXT-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TJ/TJMATHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/TJMATHER/XML-Filter-SAXT-0.01
COMMENT=	Replicates SAX events to several SAX event handlers

CONFLICTS+=	p5-libxml-enno-[0-9]*

DEPENDS+=	p5-XML-SAX>=0.12:../../textproc/p5-XML-SAX

PERL5_PACKLIST=	auto/XML/Filter/SAXT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
