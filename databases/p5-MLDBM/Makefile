# $NetBSD: Makefile,v 1.5 2001/10/18 15:20:09 veego Exp $
#

DISTNAME=		MLDBM-2.00
PKGNAME=		p5-MLDBM-2.00
SVR4_PKGNAME=		p5mld
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/MLDBM/MLDBM.html
COMMENT=		perl5 module for storing arbitrary data in tied hashes

DEPENDS+= 		{p5-Data-Dumper-[0-9]*,perl>=5.6.1nb2}:../../lang/perl5

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MLDBM/.packlist

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
