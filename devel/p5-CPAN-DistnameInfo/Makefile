# $NetBSD: Makefile,v 1.22 2023/07/06 09:38:40 wiz Exp $

DISTNAME=	CPAN-DistnameInfo-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN-DistnameInfo
COMMENT=	Perl 5 module to extract distname and version from distfile
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CPAN/DistnameInfo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
