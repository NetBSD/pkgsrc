# $NetBSD: Makefile,v 1.13 2017/06/12 12:36:23 maya Exp $
#

DISTNAME=	IPC-PubSub-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IPC-PubSub/
COMMENT=	Perl 5 module providing interprocess publish/subscribe channels

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/IPC/PubSub/.packlist

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-DBM-Deep>=1.00:../../databases/p5-DBM-Deep
DEPENDS+=	p5-Data-UUID-[0-9]*:../../devel/p5-Data-UUID

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
