# $NetBSD: Makefile,v 1.29 2021/05/24 19:51:17 wiz Exp $

DISTNAME=	OOTools-2.41
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SK/SKNPP/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/DOMIZIO/OOTools-2.21
COMMENT=	Perl module collection to easily create constructors methods
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

PERL5_PACKLIST=		auto/Class/props/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
