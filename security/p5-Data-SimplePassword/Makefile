# $NetBSD: Makefile,v 1.3 2008/06/20 01:09:34 joerg Exp $
#

DISTNAME=		Data-SimplePassword-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Data-SimplePassword/
COMMENT=		Simple random password generator

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=        	p5-Crypt-Random-[0-9]*:../../security/p5-Crypt-Random

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/SimplePassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
