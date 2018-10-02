# $NetBSD: Makefile,v 1.12 2018/10/02 00:47:31 wen Exp $

DISTNAME=	Net-IDN-Encode-2.401
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/C/CF/CFAERBER/
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-IDN-Encode/
COMMENT=	IDN, Internationalized Domain Names (Encode, UTS46, Punycode)
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

PERL5_REQD+=	5.7.3

PERL5_PACKLIST=	auto/Net/IDN/Encode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
