# $NetBSD: Makefile,v 1.13 2019/06/30 20:14:19 nia Exp $

DISTNAME=	AnyEvent-BDB-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/AnyEvent-BDB
COMMENT=	Perl 5 module providing truly asynchronous berkeley db access
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/AnyEvent/BDB/.packlist

DEPENDS+=	p5-AnyEvent>=3.81:../../devel/p5-AnyEvent
DEPENDS+=	p5-BDB>=1.5:../../databases/p5-BDB

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
