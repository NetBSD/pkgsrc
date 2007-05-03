# $NetBSD: Makefile,v 1.28 2007/05/03 12:30:20 wiz Exp $

DISTNAME=	IO-Socket-SSL-1.05
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5iss
CATEGORIES=	security net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Socket-SSL/
COMMENT=	Perl5 SSL socket interface class

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Net-SSLeay>=1.26:../../security/p5-Net-SSLeay

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IO/Socket/SSL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
