# $NetBSD: Makefile,v 1.9 2007/04/04 14:41:23 tv Exp $
#

DISTNAME=		GnuPG-Interface-0.34
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnupg-interface/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gnupg-interface.sourceforge.net/
COMMENT=		Perl interface to GnuPG

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Class-MakeMethods>=1.010:../../devel/p5-Class-MakeMethods
DEPENDS+=		gnupg>=1.2.3:../../security/gnupg

PERL5_PACKLIST=		auto/GnuPG/Interface/.packlist

pre-configure:
	cd ${WRKSRC}/lib/GnuPG && for f in *.pm; do \
		${SED} -e 's/use Class::MethodMaker/use Class::MakeMethods::Emulator::MethodMaker/' $$f > $$f.new && \
		${MV} -f $$f.new $$f; \
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
