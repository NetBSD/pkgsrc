# $NetBSD: Makefile,v 1.20 2010/08/21 16:33:23 seb Exp $
#

DISTNAME=		Class-ReturnValue-0.55
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5clv
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Class-ReturnValue/
COMMENT=		Perl5 module for return-value object

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Class/ReturnValue/.packlist

DEPENDS+=		p5-Devel-StackTrace-[0-9]*:../../devel/p5-Devel-StackTrace

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
