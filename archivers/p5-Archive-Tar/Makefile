# $NetBSD: Makefile,v 1.2 2001/10/23 19:27:31 veego Exp $

DISTNAME=		Archive-Tar-0.22
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tar
CATEGORIES=		archivers perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module interface to manipulate tar files

DEPENDS+=		p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib

USE_PERL5=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Archive/Tar/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
