# $NetBSD: Makefile,v 1.11 2001/11/26 06:50:07 jlam Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:06 jfitz Exp
#

DISTNAME=		Business-CreditCard-0.1
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5buc
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Business-CreditCard/CreditCard.html
COMMENT=		perl5 module to validate/generate credit card checksums/names

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Business/CreditCard/.packlist

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
