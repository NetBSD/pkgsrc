# $NetBSD: Makefile,v 1.2 2001/10/05 14:35:16 abs Exp $

DISTNAME=	MLDBM-Sync-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module for safe concurrent access to MLDBM databases

DEPENDS+= 	p5-MLDBM-[0-9]*:../../databases/p5-MLDBM
DEPENDS+= 	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/MLDBM/Sync/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
