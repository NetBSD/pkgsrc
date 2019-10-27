# $NetBSD: Makefile,v 1.26 2019/10/27 13:55:28 mef Exp $

DISTNAME=	OOTools-2.41
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SK/SKNPP/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/DOMIZIO/OOTools-2.21
COMMENT=	Perl module collection to easily create constructors methods
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

PERL5_PACKLIST=		auto/Class/props/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
