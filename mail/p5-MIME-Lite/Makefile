# $NetBSD: Makefile,v 1.4 2002/10/07 22:34:25 seb Exp $

DISTNAME=		MIME-Lite-2.111
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mil
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		norm@sandbox.org.uk
COMMENT=		perl5 module for simple creation of MIME email messages

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MIME/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
