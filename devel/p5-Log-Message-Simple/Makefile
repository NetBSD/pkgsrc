# $NetBSD: Makefile,v 1.3 2016/06/08 19:23:08 wiz Exp $

DISTNAME=	Log-Message-Simple-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/B/BI/BINGOS/
COMMENT=	Simple - Simplified interface to Log::Message
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Log-Message-[0-9]*:../../devel/p5-Log-Message

# url2pkg-marker (please do not remove this line.)
PERL5_PACKLIST=	auto/Log/Message/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
