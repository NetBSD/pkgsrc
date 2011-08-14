# $NetBSD: Makefile,v 1.6 2011/08/14 14:42:51 obache Exp $
#

DISTNAME=	pcsc-perl-1.4.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/pcsc-perl/

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://ludovic.rousseau.free.fr/softwares/pcsc-perl/
COMMENT=	Allows communication with a smart card from a Perl script

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE=	MakeMaker

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
