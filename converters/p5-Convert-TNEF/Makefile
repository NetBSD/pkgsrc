# $NetBSD: Makefile,v 1.5 2003/06/02 01:21:16 jschauma Exp $

DISTNAME=		Convert-TNEF-0.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tnf
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		perl5 module interface to read TNEF files

DEPENDS+=		p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/TNEF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
