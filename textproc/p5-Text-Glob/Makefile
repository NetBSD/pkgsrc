# $NetBSD: Makefile,v 1.23 2019/06/30 20:17:01 nia Exp $

DISTNAME=	Text-Glob-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
