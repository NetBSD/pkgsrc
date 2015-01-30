# $NetBSD: Makefile,v 1.8 2015/01/30 09:53:29 mef Exp $

DISTNAME=	Clone-Fast-0.96
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Clone/}
# as of 2015-01-30, above doesn't make it
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/J/JJ/JJORE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Clone-Fast/
COMMENT=	Natively copying Perl data structures
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Clone/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
