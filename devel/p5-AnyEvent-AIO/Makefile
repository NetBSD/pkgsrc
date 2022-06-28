# $NetBSD: Makefile,v 1.16 2022/06/28 11:31:52 wiz Exp $

DISTNAME=	AnyEvent-AIO-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/AnyEvent-AIO
COMMENT=	Perl 5 module providing truly asynchronous file and directory I/O
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/AnyEvent/AIO/.packlist

DEPENDS+=	p5-AnyEvent>=3.4:../../devel/p5-AnyEvent
DEPENDS+=	p5-IO-AIO>=3:../../devel/p5-IO-AIO

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
