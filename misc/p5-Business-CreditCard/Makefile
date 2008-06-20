# $NetBSD: Makefile,v 1.24 2008/06/20 01:09:26 joerg Exp $
#

DISTNAME=		Business-CreditCard-0.28
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5buc
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Business-CreditCard/CreditCard.html
COMMENT=		Perl5 module to validate/generate credit card checksums/names

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Business/CreditCard/.packlist

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
