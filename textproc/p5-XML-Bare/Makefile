# $NetBSD: Makefile,v 1.13 2019/06/30 20:17:06 nia Exp $
#

DISTNAME=	XML-Bare-0.53
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Bare
COMMENT=	Minimal XML parser implemented via a C state engine
LICENSE=	gnu-gpl-v2

PERL5_PACKLIST=	auto/XML/Bare/.packlist
USE_LANGUAGES=	c

SUBST_CLASSES+=		perl
SUBST_MESSAGE.perl=	Fixing the path of perl.
SUBST_STAGE.perl=	pre-configure
SUBST_FILES.perl=	Bare.pm
SUBST_SED.perl=		-e "s,/usr/bin/perl,${PREFIX}/bin/perl,g"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
