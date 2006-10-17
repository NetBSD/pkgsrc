# $NetBSD: Makefile,v 1.8 2006/10/17 14:20:21 obache Exp $
#

DISTNAME=	Authen-SASL-2.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://search.cpan.org/dist/Authen-SASL/
COMMENT=	Perl module to handle SASL authentication

PERL5_PACKLIST=	auto/Authen/SASL/.packlist
MAKE_PARAMS+=	< /dev/null

.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
