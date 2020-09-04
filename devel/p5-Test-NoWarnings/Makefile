# $NetBSD: Makefile,v 1.24 2020/09/04 13:45:15 wiz Exp $

DISTNAME=	Test-NoWarnings-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-NoWarnings
COMMENT=	Make sure tests of Perl5 modules did not emit any warnings
LICENSE=	gnu-lgpl-v2.1

PERL5_PACKLIST=		auto/Test/NoWarnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
