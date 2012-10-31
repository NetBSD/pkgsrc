# $NetBSD: Makefile,v 1.6 2012/10/31 11:18:50 asau Exp $
#

DISTNAME=	Proc-Background-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Proc-Background/
COMMENT=	Perl 5 module prodiving an interface to background process management
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=	auto/Proc/Background/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
