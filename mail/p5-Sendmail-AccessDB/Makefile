# $NetBSD: Makefile,v 1.7 2004/04/25 04:09:37 snj Exp $

DISTNAME=	Sendmail-AccessDB-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sendmail/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.megacity.org/software.html
COMMENT=	Perl5 module for manipulating the sendmail accessdb

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Sendmail/AccessDB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
