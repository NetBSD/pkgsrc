# $NetBSD: Makefile,v 1.2 2026/01/14 02:47:56 scole Exp $

DISTNAME=	Test-Harness-Straps-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/Test-Harness-Straps
COMMENT=	Detailed analysis of perl test results
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=	perl

DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build

SUBST_CLASSES+=		nosleep
SUBST_STAGE.nosleep=	pre-configure
SUBST_MESSAGE.nosleep=	Removing sleep
SUBST_FILES.nosleep=	Build.PL
SUBST_SED.nosleep=	-e 's/sleep 2;//'

do-configure:
	cd ${WRKSRC} && ${PERL5} Build.PL --create_packlist 0 \
		--install_base ${DESTDIR}${PREFIX}

do-build:
	cd ${WRKSRC} && ${PERL5} ./Build

do-test:
	cd ${WRKSRC} && ${PERL5} ./Build test

do-install:
	cd ${WRKSRC} && ${PERL5} ./Build install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
