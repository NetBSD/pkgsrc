# $NetBSD: Makefile,v 1.2 2001/02/17 17:51:50 wiz Exp $

DISTNAME=		Font-AFM-1.18
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		print perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 modules for parsing PostScript font metrics files

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Font/AFM/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
