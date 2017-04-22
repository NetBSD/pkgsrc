# $NetBSD: Makefile,v 1.25 2017/04/22 06:25:44 mef Exp $

DISTNAME=	Make-1.1.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Make/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ni-s.u-net.com/
COMMENT=	Perl5 module implementing 'make' in Perl
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+= p5-Test-Compile-[0-9]*:../../devel/p5-Test-Compile

WRKSRC=		${WRKDIR}/${DISTNAME:C/-[0-9.]+//}
REPLACE_PERL=	pmake

PERL5_PACKLIST=		auto/Make/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
