# $NetBSD: Makefile,v 1.7 2001/02/17 17:49:59 wiz Exp $
#

DISTNAME=	Digest-MD5-2.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl5 extension interface for various message digest algorithms

CONFLICTS+=	p5-MD5-[0-9]*

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Digest/MD5/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
