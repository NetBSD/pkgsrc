# $NetBSD: Makefile,v 1.31 2019/06/30 20:16:02 nia Exp $

DISTNAME=	Want-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/ROBIN/} # this is a hack

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Want
COMMENT=	Perl module providing a generalisation of wantarray
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Want/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
