# $NetBSD: Makefile,v 1.7 1998/08/20 15:16:49 tsarna Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:11 jfitz Exp
#

DISTNAME=		Data-Dumper-2.07
PKGNAME=		p5-Data-Dumper-2.07
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Data-Dumper/Dumper.html

USE_PERL5=		yes

WRKSRC=			${WRKDIR}/Data-Dumper-2.07

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
