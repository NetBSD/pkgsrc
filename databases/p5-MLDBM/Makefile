# $NetBSD: Makefile,v 1.1.1.1 2001/03/25 05:14:28 mjl Exp $
#

DISTNAME=	MLDBM-2.00
PKGNAME=	p5-MLDBM-2.0
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc@netbsd.org
COMMENT= 	Perl module store multidimensional hash structures in tied hashes

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/MLDBM/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
