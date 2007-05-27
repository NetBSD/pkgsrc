# $NetBSD: Makefile,v 1.6 2007/05/27 09:24:06 heinz Exp $

DISTNAME=		Email-Abstract-2.132
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ema
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Email-Abstract/
COMMENT=		Perl5 module for writing representation-independent mail handling code

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Email-Simple>=1.91:../../mail/p5-Email-Simple
DEPENDS+=		p5-Module-Pluggable>=1.5:../../devel/p5-Module-Pluggable

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Email/Abstract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
