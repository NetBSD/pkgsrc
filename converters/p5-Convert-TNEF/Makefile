# $NetBSD: Makefile,v 1.4 2002/10/27 20:48:56 seb Exp $

DISTNAME=		Convert-TNEF-0.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tnf
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module interface to read TNEF files

DEPENDS+=		p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/TNEF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
