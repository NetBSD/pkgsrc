# $NetBSD: Makefile,v 1.15 2005/02/18 13:12:12 wiz Exp $

DISTNAME=	IO-Socket-SSL-0.96
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5iss
CATEGORIES=	security net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Socket-SSL/
COMMENT=	Perl5 SSL socket interface class

DEPENDS+=	p5-Net-SSLeay>=1.26:../../security/p5-Net-SSLeay

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Socket/SSL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
