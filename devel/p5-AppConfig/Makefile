# $NetBSD: Makefile,v 1.7 2003/12/03 22:14:45 kristerw Exp $

DISTNAME=	AppConfig-1.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5apc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/ABW/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kfs.org/~abw/
COMMENT=	Perl5 module for parsing config files and command line arguments

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/AppConfig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
