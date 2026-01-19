# $NetBSD: Makefile,v 1.54 2026/01/19 07:36:35 wiz Exp $

DISTNAME=	MIME-Types-2.30
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MARKOV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://perl.overmeer.net/mimetypes/
COMMENT=	Definition of MIME types
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MIME/Types/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
