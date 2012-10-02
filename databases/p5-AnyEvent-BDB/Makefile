# $NetBSD: Makefile,v 1.4 2012/10/02 21:25:24 asau Exp $

DISTNAME=	AnyEvent-BDB-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5bdb
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AnyEvent-BDB/
COMMENT=	Perl 5 module providing truly asynchronous berkeley db access
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/AnyEvent/BDB/.packlist

DEPENDS+=	p5-AnyEvent>=3.81:../../devel/p5-AnyEvent
DEPENDS+=	p5-BDB>=1.5:../../databases/p5-BDB

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
