# $NetBSD: Makefile,v 1.1.1.1 2001/10/22 05:46:50 martti Exp $

DISTNAME=		Archive-Zip-0.11
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5zip
CATEGORIES=		archivers perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Archive}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module interface to manipulate zip files

DEPENDS+=		p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib

USE_PERL5=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Archive/Zip/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
