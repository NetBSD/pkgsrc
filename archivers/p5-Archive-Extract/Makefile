# $NetBSD: Makefile,v 1.16 2024/07/29 11:28:16 wen Exp $

DISTNAME=	Archive-Extract-0.88
PKGNAME=	p5-${DISTNAME}
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
