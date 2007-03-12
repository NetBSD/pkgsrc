# $NetBSD: Makefile,v 1.2 2007/03/12 09:58:10 abs Exp $
#

DISTNAME=		Data-SimplePassword-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Data-SimplePassword/
COMMENT=		Simple random password generator

DEPENDS+=        	p5-Crypt-Random-[0-9]*:../../security/p5-Crypt-Random

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/SimplePassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
