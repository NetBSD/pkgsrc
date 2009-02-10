# $NetBSD: Makefile,v 1.11 2009/02/10 14:34:25 rhaen Exp $

DISTNAME=		Email-Abstract-3.001
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ema
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Email-Abstract/
COMMENT=		Perl5 module for writing representation-independent mail handling code

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Email-Simple>=1.91:../../mail/p5-Email-Simple
DEPENDS+=		p5-Module-Pluggable>=1.5:../../devel/p5-Module-Pluggable

PERL5_PACKLIST=		auto/Email/Abstract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
