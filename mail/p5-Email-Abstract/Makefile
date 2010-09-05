# $NetBSD: Makefile,v 1.14 2010/09/05 12:09:22 sno Exp $

DISTNAME=	Email-Abstract-3.002
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
SVR4_PKGNAME=	p5ema
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Abstract/
COMMENT=	Perl5 module for writing representation-independent mail handling code
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

# Class::ISA was first released with perl v5.7.3 and removed from v5.13.1
DEPENDS+=	p5-Class-ISA>=0.20:../../devel/p5-Class-ISA
DEPENDS+=	p5-Email-Simple>=1.9100:../../mail/p5-Email-Simple
DEPENDS+=	{perl>5.10,p5-Module-Pluggable>=1.5}:../../devel/p5-Module-Pluggable

PERL5_PACKLIST=		auto/Email/Abstract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
