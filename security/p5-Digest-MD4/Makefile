# $NetBSD: Makefile,v 1.1.1.1 2001/09/19 03:19:31 mjl Exp $
#

DISTNAME=		Digest-MD4-1.1
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for MD4 hash algorithm

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/MD4/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
