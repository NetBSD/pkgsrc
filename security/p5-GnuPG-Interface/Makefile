# $NetBSD: Makefile,v 1.2 2005/03/04 20:57:50 tv Exp $
#

DISTNAME=		GnuPG-Interface-0.34
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnupg-interface/}

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://gnupg-interface.sourceforge.net/
COMMENT=		Perl interface to GnuPG

DEPENDS+=		p5-Class-MakeMethods>=1.010:../../devel/p5-Class-MakeMethods
DEPENDS+=		gnupg>=1.2.3:../../security/gnupg

USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GnuPG/Interface/.packlist

pre-configure:
	cd ${WRKSRC}/lib/GnuPG && for f in *.pm; do \
		${SED} -e 's/use Class::MethodMaker/use Class::MakeMethods::Emulator::MethodMaker/' $$f > $$f.new && \
		${MV} -f $$f.new $$f; \
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
