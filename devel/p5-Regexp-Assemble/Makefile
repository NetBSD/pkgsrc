# $NetBSD: Makefile,v 1.17 2017/09/17 12:59:48 wiz Exp $

DISTNAME=	Regexp-Assemble-0.38
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Regexp-Assemble/
COMMENT=	Perl 5 module to assemble multiple regular expressions
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Regexp/Assemble/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
