# $NetBSD: Makefile,v 1.8 2013/12/09 14:17:51 obache Exp $
#

DISTNAME=		Crypt-GPG-1.63
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~agul/Crypt-GPG/
COMMENT=		Object Oriented Interface to GnuPG

DEPENDS+=		gnupg-[0-9]*:../../security/gnupg
DEPENDS+=		p5-IPC-Run-[0-9]*:../../devel/p5-IPC-Run
DEPENDS+=		{perl>=5.6.1,p5-File-Temp-[0-9]*}:../../devel/p5-File-Temp
DEPENDS+=		p5-TimeDate-[0-9]*:../../time/p5-TimeDate

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# It defaults to a gpg path in /usr/local, which is not helpful
SUBST_CLASSES+=		local
SUBST_FILES.local=	GPG.pm
SUBST_SED.local=	-e s,/usr/local,${PREFIX},
SUBST_STAGE.local=	post-patch

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/GPG/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
