# $NetBSD: Makefile,v 1.3 2010/08/21 16:35:07 seb Exp $
#

DISTNAME=	Mail-RFC822-Address-0.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~pdwarren/Mail-RFC822-Address-0.3/
COMMENT=	Perl extension for validating email addresses according to RFC822
LICENSE=	mit

DEPENDS+=	p5-ExtUtils-MakeMaker-[0-9]*:../../devel/p5-ExtUtils-MakeMaker

PERL5_PACKLIST=	auto/Mail/RFC822/Address/.packlist
USE_LANGUAGES=	# none

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
