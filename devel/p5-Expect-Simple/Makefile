# $NetBSD: Makefile,v 1.4 2012/10/03 21:54:57 wiz Exp $

DISTNAME=	Expect-Simple-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Expect/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Expect-Simple/
COMMENT=	Perl 5 module providing a wrapper around the Expect module
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Expect-[0-9]*:../../devel/p5-Expect

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Expect/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
