# $NetBSD: Makefile,v 1.5 2019/08/11 13:19:44 wiz Exp $

DISTNAME=	Log-Any-Adapter-Callback-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Any-Adapter-Callback/
COMMENT=	Perl5 module to send Log::Any logs to a subroutine
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Log-Any-[0-9]*:../../devel/p5-Log-Any

PERL5_PACKLIST=		auto/Log/Any/Adapter/Callback/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
