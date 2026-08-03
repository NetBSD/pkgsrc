# $NetBSD: Makefile,v 1.24 2026/08/03 13:12:32 wiz Exp $

DISTNAME=	XML-Bare-0.53
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

PATCHFILES+=		CVE-2026-13401-r1.patch
PATCH_SITES+=		https://security.metacpan.org/patches/X/XML-Bare/0.53/

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
