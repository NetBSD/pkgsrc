# $NetBSD: Makefile,v 1.20 2022/06/28 11:36:28 wiz Exp $

DISTNAME=	Template-Tiny-1.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Template-Tiny
COMMENT=	Template Toolkit reimplemented in as little code as possible
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Capture-Tiny>=0.07:../../devel/p5-Capture-Tiny

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Template/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
