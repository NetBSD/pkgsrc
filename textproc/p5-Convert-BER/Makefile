# $NetBSD: Makefile,v 1.9 2003/06/02 01:16:36 jschauma Exp $
#

DISTNAME=	Convert-BER-1.31
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ber
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl class to encode and decode objects using Basic Encoding Rules (BER)

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/BER/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
