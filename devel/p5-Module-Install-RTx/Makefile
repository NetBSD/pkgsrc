# $NetBSD: Makefile,v 1.3 2008/07/24 02:03:39 seb Exp $

DISTNAME=	Module-Install-RTx-0.23
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mir
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Install-RTx/
COMMENT=	Perl5 module for building and installing RT extensions

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Module-Install-[0-9]*:../../devel/p5-Module-Install

PERL5_PACKLIST=		auto/Module/Install/RTx/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
