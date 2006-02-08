# $NetBSD: Makefile,v 1.1.1.1 2006/02/08 15:11:12 seb Exp $
#

DISTNAME=	Carp-Assert-More-1.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cam
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Carp-Assert-More/
COMMENT=	Perl5 module providing convenience wrappers around Carp::Assert

PERL5_PACKLIST=		auto/Carp/Assert/More/.packlist

DEPENDS+=	p5-Carp-Assert-[0-9]*:../../devel/p5-Carp-Assert
DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
