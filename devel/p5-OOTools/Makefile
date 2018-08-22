# $NetBSD: Makefile,v 1.23 2018/08/22 09:44:26 wiz Exp $

DISTNAME=	OOTools-2.4
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SK/SKNPP/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/~domizio/OOTools/
COMMENT=	Perl module collection to easily create constructors methods
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

PERL5_PACKLIST=		auto/Class/props/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
