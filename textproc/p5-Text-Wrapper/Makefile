# $NetBSD: Makefile,v 1.35 2022/06/28 11:36:37 wiz Exp $
#

DISTNAME=	Text-Wrapper-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Wrapper
COMMENT=	Perl5 module that provides simple word wrapping
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Wrapper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
