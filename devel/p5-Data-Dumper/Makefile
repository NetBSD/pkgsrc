# $NetBSD: Makefile,v 1.16 2001/06/07 04:25:31 jlam Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:11 jfitz Exp

.include "../../lang/perl5/Makefile.common"

PKGNAME=	p5-Data-Dumper-2.102
CATEGORIES+=	devel
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.perldoc.com/perl5.6/lib/Data/Dumper.html
COMMENT=	perl5 module for stringified perl data structures

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Data/Dumper/.packlist

EXTRACT_ELEMENTS=	${DISTNAME}/ext/Data/Dumper
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
