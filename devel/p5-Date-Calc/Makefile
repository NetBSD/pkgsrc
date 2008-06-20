# $NetBSD: Makefile,v 1.22 2008/06/20 01:09:15 joerg Exp $
#

DISTNAME=	Date-Calc-5.4
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dca
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://engelschall.com/u/sb/download/
COMMENT=	Perl5 module for Gregorian calendar date calculations

DEPENDS+=	p5-Bit-Vector-[0-9]*:../../devel/p5-Bit-Vector

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Date/Calc/.packlist

post-patch:
	@rm -rf ${WRKSRC}/lib/Carp

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
