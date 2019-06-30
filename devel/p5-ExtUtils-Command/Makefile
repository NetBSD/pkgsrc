# $NetBSD: Makefile,v 1.17 2019/06/30 20:14:58 nia Exp $

DISTNAME=	ExtUtils-Command-1.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/ExtUtils-Command
COMMENT=	Perl 5 functions to replace common UNIX commands in Makefiles
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/ExtUtils/Command/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
