# $NetBSD: Makefile,v 1.8 2006/02/05 23:11:04 joerg Exp $

DISTNAME=	XML-Encoding-1.01
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CO/COOPERCL/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Encoding-1.01/
COMMENT=	Perl module for parsing XML encoding maps

DEPENDS+=	p5-XML-Parser>=2.18:../../textproc/p5-XML-Parser

PERL5_PACKLIST=	auto/XML/Encoding/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
