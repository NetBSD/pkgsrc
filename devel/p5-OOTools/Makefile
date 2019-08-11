# $NetBSD: Makefile,v 1.25 2019/08/11 13:20:03 wiz Exp $

DISTNAME=	OOTools-2.4
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SK/SKNPP/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/DOMIZIO/OOTools-2.21
COMMENT=	Perl module collection to easily create constructors methods
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

PERL5_PACKLIST=		auto/Class/props/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
