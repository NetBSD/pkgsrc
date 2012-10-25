# $NetBSD: Makefile,v 1.21 2012/10/25 06:56:33 asau Exp $
#

DISTNAME=	Text-Wrapper-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5twr
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Wrapper/
COMMENT=	Perl5 module that provides simple word wrapping

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		auto/Text/Wrapper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
