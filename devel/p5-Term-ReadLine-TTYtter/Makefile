# $NetBSD: Makefile,v 1.15 2025/07/04 08:46:42 wiz Exp $

DISTNAME=	Term-ReadLine-TTYtter-1.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-ReadLine-TTYtter
COMMENT=	Perl 5 module providing minimal interface to Readline libraries
LICENSE=	${PERL5_LICENSE}

CONFLICTS=	p5-Term-ReadLine-Perl-[0-9]*

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Term/ReadLine/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
