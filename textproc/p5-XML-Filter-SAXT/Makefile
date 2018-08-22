# $NetBSD: Makefile,v 1.21 2018/08/22 09:47:07 wiz Exp $

DISTNAME=	XML-Filter-SAXT-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TJ/TJMATHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Filter-SAXT-0.01/
COMMENT=	Replicates SAX events to several SAX event handlers

CONFLICTS+=	p5-libxml-enno-[0-9]*

DEPENDS+=	p5-XML-SAX>=0.12:../../textproc/p5-XML-SAX

PERL5_PACKLIST=	auto/XML/Filter/SAXT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
