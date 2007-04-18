# $NetBSD: Makefile,v 1.40 2007/04/18 23:41:51 wiz Exp $

DISTNAME=	MailTools-1.76
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mto
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MailTools/
COMMENT=	Perl5 modules related to mail applications

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-Net>=1.09:../../net/p5-Net

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Mail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
