# $NetBSD: Makefile,v 1.6 2003/06/02 01:21:16 jschauma Exp $

DISTNAME=		Convert-UUlib-0.213
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5uul
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		perl5 module interface to the uulib library

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/UUlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
