# $NetBSD: Makefile,v 1.7 2004/12/20 11:31:04 grant Exp $

DISTNAME=		MIME-Lite-2.111
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mil
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		norm@sandbox.org.uk
COMMENT=		Perl5 module for simple creation of MIME email messages

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MIME/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
