# $NetBSD: Makefile,v 1.18 2021/09/18 13:51:58 wen Exp $
#

DISTNAME=	Proc-Background-1.22
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
