# $NetBSD: Makefile,v 1.1.1.1 2002/07/16 15:26:01 wiz Exp $

DISTNAME=		Font-AFM-1.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5fon
CATEGORIES=		fonts perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 modules for parsing PostScript font metrics files

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Font/AFM/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
