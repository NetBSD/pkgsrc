# $NetBSD: Makefile,v 1.4 2003/06/02 01:18:40 jschauma Exp $

DISTNAME=	Sendmail-AccessDB-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sendmail/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.megacity.org/software.html
COMMENT=	perl5 module for manipulating the sendmail accessdb

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Sendmail/AccessDB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
