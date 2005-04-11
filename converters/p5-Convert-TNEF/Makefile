# $NetBSD: Makefile,v 1.13 2005/04/11 21:45:08 tv Exp $

DISTNAME=		Convert-TNEF-0.17
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tnf
PKGREVISION=		1
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module interface to read TNEF files

DEPENDS+=		p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/TNEF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
