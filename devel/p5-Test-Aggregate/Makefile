# $NetBSD: Makefile,v 1.1.1.1 2009/04/29 19:37:57 sno Exp $

DISTNAME=	Test-Aggregate-0.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Aggregate/
COMMENT=	Aggregate *.t tests to make them run faster
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Test-Harness>=3.09:../../devel/p5-Test-Harness
DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
DEPENDS+=	p5-Data-Dump-Streamer>=1.11:../../devel/p5-Data-Dump-Streamer

BUILD_DEPENDS+=	p5-Test-Simple>=0.74:../../devel/p5-Test-Simple

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Test/Aggregate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
