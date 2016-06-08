# $NetBSD: Makefile,v 1.32 2016/06/08 19:22:37 wiz Exp $

DISTNAME=	CPAN-Perl-Releases-2.78
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CPAN-Perl-Releases/
COMMENT=	Mapping Perl releases on CPAN to the location of the tarballs
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CPAN/Perl/Releases/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
