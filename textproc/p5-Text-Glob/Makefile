# $NetBSD: Makefile,v 1.18 2016/06/08 19:24:38 wiz Exp $

DISTNAME=	Text-Glob-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5

CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Text-Glob/
COMMENT=	Match globbing patterns against text
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Glob/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
