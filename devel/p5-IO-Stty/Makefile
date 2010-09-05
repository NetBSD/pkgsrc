# $NetBSD: Makefile,v 1.20 2010/09/05 09:07:20 sno Exp $

DISTNAME=	IO-Stty-0.03
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	5
SVR4_PKGNAME=	p5ist
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl class for I/O on tty devices
HOMEPAGE=	http://search.cpan.org/dist/IO-Stty/
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	#empty

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/IO/Stty/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
