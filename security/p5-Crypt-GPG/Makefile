# $NetBSD: Makefile,v 1.18 2019/07/01 21:35:51 nia Exp $
#

DISTNAME=		Crypt-GPG-1.64
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-GPG
COMMENT=		Object Oriented Interface to GnuPG
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		gnupg-[0-9]*:../../security/gnupg
DEPENDS+=		p5-IPC-Run-[0-9]*:../../devel/p5-IPC-Run
#DEPENDS+=		{perl>=5.6.1,p5-File-Temp-[0-9]*}:../../devel/p5-File-Temp
DEPENDS+=		p5-TimeDate-[0-9]*:../../time/p5-TimeDate

# It defaults to a gpg path in /usr/local, which is not helpful
SUBST_CLASSES+=		local
SUBST_FILES.local=	GPG.pm
SUBST_SED.local=	-e s,/usr/local,${PREFIX},
SUBST_STAGE.local=	pre-configure

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/GPG/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
