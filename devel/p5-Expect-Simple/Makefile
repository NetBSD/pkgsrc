# $NetBSD: Makefile,v 1.1.1.1 2009/02/07 17:37:00 seb Exp $
#

DISTNAME=	Expect-Simple-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Expect/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Expect-Simple/
COMMENT=	Perl 5 module providing a wrapper around the Expect module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Expect/Simple/.packlist

DEPENDS+=	p5-Expect-[0-9]*:../../devel/p5-Expect

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
