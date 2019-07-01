# $NetBSD: Makefile,v 1.24 2019/07/01 21:35:41 nia Exp $

DISTNAME=	OOTools-2.4
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	1
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
