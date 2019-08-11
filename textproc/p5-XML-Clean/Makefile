# $NetBSD: Makefile,v 1.16 2019/08/11 13:23:51 wiz Exp $

DISTNAME=	XML-Clean-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PK/PKUBANEK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Clean
COMMENT=	Ensure, that *(HTML)* text pass throught an XML parser

PERL5_PACKLIST= auto/XML/Clean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
