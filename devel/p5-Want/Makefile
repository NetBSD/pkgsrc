# $NetBSD: Makefile,v 1.23 2015/04/25 08:30:31 mef Exp $

DISTNAME=	Want-0.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/ROBIN/} # this is a hack

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Want/
COMMENT=	Perl module providing a generalisation of wantarray
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Want/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
