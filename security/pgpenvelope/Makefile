# $NetBSD: Makefile,v 1.17 2013/12/09 14:17:52 obache Exp $
#

DISTNAME=		pgpenvelope-2.10.2
PKGREVISION=		10
CATEGORIES=		security mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pgpenvelope/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pgpenvelope.sourceforge.net/
COMMENT=		GnuPG and Pine/Procmail integration tool

DEPENDS+=		p5-AppConfig>=1.52:../../devel/p5-AppConfig
DEPENDS+=		p5-Class-MakeMethods>=1.010:../../devel/p5-Class-MakeMethods
DEPENDS+=		p5-GnuPG-Interface>=0.34nb2:../../security/p5-GnuPG-Interface
DEPENDS+=		p5-String-Approx>=3.13:../../textproc/p5-String-Approx
DEPENDS+=		p5-Term-ReadKey>=2.14:../../devel/p5-Term-ReadKey
DEPENDS+=		{perl>=5.8.1,p5-Term-ReadLine>=1.01}:../../devel/p5-Term-ReadLine

PERL5_PACKLIST=		auto/pgpenvelope/.packlist

pre-configure:
	cd ${WRKSRC}/lib/PGPEnvelope && for f in *.pm; do \
		${SED} -e 's/use Class::MethodMaker/use Class::MakeMethods::Emulator::MethodMaker/' $$f > $$f.new && \
		${MV} -f $$f.new $$f; \
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
