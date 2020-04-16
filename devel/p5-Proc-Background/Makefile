# $NetBSD: Makefile,v 1.15 2020/04/16 15:09:12 mef Exp $
#

DISTNAME=	Proc-Background-1.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Proc-Background
COMMENT=	Perl 5 module prodiving an interface to background process management
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=	auto/Proc/Background/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
