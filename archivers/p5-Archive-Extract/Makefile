# $NetBSD: Makefile,v 1.15 2023/07/06 09:38:08 wiz Exp $

DISTNAME=	Archive-Extract-0.86
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Archive-Extract
COMMENT=	Perl5 module interface to manipulate zip files
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Archive/Extract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
