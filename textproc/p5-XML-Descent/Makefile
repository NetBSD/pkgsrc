# $NetBSD: Makefile,v 1.7 2019/08/11 13:23:52 wiz Exp $

DISTNAME=	XML-Descent-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AN/ANDYA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/ANDYA/XML-Descent-1.04
COMMENT=	Recursive descent XML parsing

DEPENDS+=	p5-XML-TokeParser>=0.05:../../textproc/p5-XML-TokeParser

PERL5_PACKLIST= auto/XML/Descent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
