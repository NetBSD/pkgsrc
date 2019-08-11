# $NetBSD: Makefile,v 1.17 2019/08/11 13:23:43 wiz Exp $

DISTNAME=	Text-CharWidth-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-CharWidth
COMMENT=	Perl5 wrappers around wcwidth(3) and family

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Text/CharWidth/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
