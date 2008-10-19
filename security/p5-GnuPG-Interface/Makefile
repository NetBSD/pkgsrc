# $NetBSD: Makefile,v 1.11 2008/10/19 19:18:46 he Exp $
#

DISTNAME=		GnuPG-Interface-0.36
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=GnuPG/}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://gnupg-interface.sourceforge.net/
HOMEPAGE=		http://search.cpan.org/dist/GnuPG-Interface/
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
