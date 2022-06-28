# $NetBSD: Makefile,v 1.19 2022/06/28 11:32:37 wiz Exp $
#

DISTNAME=	IPC-PubSub-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IPC-PubSub
COMMENT=	Perl 5 module providing interprocess publish/subscribe channels

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/IPC/PubSub/.packlist

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-DBM-Deep>=1.00:../../databases/p5-DBM-Deep
DEPENDS+=	p5-Data-UUID-[0-9]*:../../devel/p5-Data-UUID

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
