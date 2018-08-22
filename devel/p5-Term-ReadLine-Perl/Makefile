# $NetBSD: Makefile,v 1.11 2018/08/22 09:44:42 wiz Exp $

DISTNAME=	Term-ReadLine-Perl-1.0303
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-ReadLine-Perl/
COMMENT=	Perl 5 module providing minimal interface to Readline libraries
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Term/ReadLine/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
