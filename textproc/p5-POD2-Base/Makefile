# $NetBSD: Makefile,v 1.16 2023/07/06 09:41:42 wiz Exp $
#

DISTNAME=	POD2-Base-0.043
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/POD2-Base
COMMENT=	Base module for translations of Perl documentation
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/POD2/Base/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
