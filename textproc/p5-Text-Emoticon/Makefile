# $NetBSD: Makefile,v 1.19 2022/06/28 11:36:31 wiz Exp $

DISTNAME=	Text-Emoticon-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Emoticon
COMMENT=	Emoticon filter class

DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

PERL5_PACKLIST=		auto/Text/Emoticon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
