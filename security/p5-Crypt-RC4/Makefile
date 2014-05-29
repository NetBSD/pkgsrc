# $NetBSD: Makefile,v 1.10 2014/05/29 23:37:22 wiz Exp $
#

DISTNAME=	Crypt-RC4-2.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Crypt-RC4/
COMMENT=	Perl5 module for the "alleged" RC4 encryption algorithm

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Crypt/RC4/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
