# $NetBSD: Makefile,v 1.3 2005/03/31 21:47:11 seb Exp $

DISTNAME=	Want-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/ROBIN/} # this is a hack

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Want/
COMMENT=	Perl module providing a generalisation of wantarray

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Want/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
