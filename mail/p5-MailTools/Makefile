# $NetBSD: Makefile,v 1.19 2002/10/07 22:34:26 seb Exp $

DISTNAME=	MailTools-1.49
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mto
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 modules related to mail applications

BUILD_DEPENDS+=	p5-Net>=1.09:../../net/p5-Net

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
