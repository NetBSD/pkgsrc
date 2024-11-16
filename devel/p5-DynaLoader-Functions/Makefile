# $NetBSD: Makefile,v 1.10 2024/11/16 12:04:09 wiz Exp $

DISTNAME=	DynaLoader-Functions-0.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Z/ZE/ZEFRAM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/DynaLoader::Functions
COMMENT=	Deconstructed dynamic C library loading
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
#PERL5_PACKLIST=	auto/DynaLoader/Function/.packlist

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	post-install
SUBST_FILES.destdir=	${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORARCH}/auto/DynaLoader/Functions/.packlist
SUBST_SED.destdir=	-e 's|^${DESTDIR}${PREFIX}|${PREFIX}|'

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
