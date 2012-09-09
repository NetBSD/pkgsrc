# $NetBSD: Makefile,v 1.54 2012/09/09 13:17:58 abs Exp $

DISTNAME=	MailTools-2.11
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mto
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MailTools/
COMMENT=	Perl5 modules related to mail applications
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-Net>=1.09:../../net/p5-Net
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

PERL5_PACKLIST=		auto/Mail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
