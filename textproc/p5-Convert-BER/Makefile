# $NetBSD: Makefile,v 1.13 2004/12/20 11:31:09 grant Exp $
#

DISTNAME=	Convert-BER-1.31
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ber
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl class to encode/decode objects using Basic Encoding Rules

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/BER/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
