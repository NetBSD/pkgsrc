# $NetBSD: Makefile,v 1.8 2004/04/25 05:12:27 minskim Exp $

DISTNAME=	Sendmail-AccessDB-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sendmail/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.megacity.org/software.html
COMMENT=	Perl5 module for manipulating the sendmail accessdb

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Sendmail/AccessDB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
