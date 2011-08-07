# $NetBSD: Makefile,v 1.4 2011/08/07 05:42:02 adam Exp $

DISTNAME=	Algorithm-CheckDigits-v1.1.1
PKGNAME=	p5-${DISTNAME:S/-v/-/}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-CheckDigits/
COMMENT=	Perl extension to generate and test check digits
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Algorithm/CheckDigits/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
