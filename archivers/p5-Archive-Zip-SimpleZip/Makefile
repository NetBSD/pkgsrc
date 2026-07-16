# $NetBSD: Makefile,v 1.2 2026/07/16 19:01:23 wiz Exp $

DISTNAME=	Archive-Zip-SimpleZip-1.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Archive::Zip::SimpleZip
COMMENT=	Perl5 module interface to read/write Zip Archives
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Archive/Zip/SimpleZip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
