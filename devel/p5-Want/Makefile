# $NetBSD: Makefile,v 1.11 2006/11/04 10:31:08 obache Exp $

DISTNAME=	Want-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/ROBIN/} # this is a hack

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Want/
COMMENT=	Perl module providing a generalisation of wantarray

PERL5_PACKLIST=		auto/Want/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
