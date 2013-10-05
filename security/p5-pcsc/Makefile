# $NetBSD: Makefile,v 1.13 2013/10/05 14:19:01 pettai Exp $

DISTNAME=	pcsc-perl-1.4.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/pcsc-perl/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ludovic.rousseau.free.fr/softwares/pcsc-perl/
COMMENT=	Allows communication with a smart card from a Perl script

PERL5_MODULE_TYPE=	MakeMaker
LICENSE=		gnu-gpl-v2

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-patch
SUBST_FILES.perl=	Card/t/test.t examples/test_iso_error.pl examples/gsm_directory.pl t/test.t test/multiple_readers.pl test/single_reader.pl
SUBST_SED.perl=		-e 's,/usr/bin/perl,${PERL5},'

PERL5_USE_PACKLIST=	yes
MAKE_PARAMS+=		INSTALLDIRS=vendor
PERL5_PACKLIST=		auto/Chipcard/PCSC/.packlist

USE_TOOLS+=		pkg-config

.include "../../lang/perl5/module.mk"
.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
