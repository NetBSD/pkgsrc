# $NetBSD: Makefile,v 1.4 2001/11/26 06:50:13 jlam Exp $

DISTNAME=		Font-AFM-1.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5fon
CATEGORIES=		print perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 modules for parsing PostScript font metrics files

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Font/AFM/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
