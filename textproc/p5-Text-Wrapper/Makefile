# $NetBSD: Makefile,v 1.32 2019/08/11 13:23:49 wiz Exp $
#

DISTNAME=	Text-Wrapper-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Wrapper
COMMENT=	Perl5 module that provides simple word wrapping
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Wrapper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
