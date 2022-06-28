# $NetBSD: Makefile,v 1.27 2022/06/28 11:36:32 wiz Exp $

DISTNAME=	Text-Glob-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/Text-Glob
COMMENT=	Match globbing patterns against text
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Glob/.packlist
# to avoid "PaxHeader" pollution and confusion
EXTRACT_USING=		bsdtar
USE_TOOLS+=		bsdtar

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
