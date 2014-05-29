# $NetBSD: Makefile,v 1.24 2014/05/29 23:37:44 wiz Exp $
#

DISTNAME=	Text-Wrapper-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5twr
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Wrapper/
COMMENT=	Perl5 module that provides simple word wrapping
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Wrapper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
