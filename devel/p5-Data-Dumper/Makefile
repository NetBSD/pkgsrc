# $NetBSD: Makefile,v 1.5 1998/04/20 11:56:22 frueauf Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:11 jfitz Exp
#

DISTNAME=		Data-Dumper-2.07
PKGNAME=		p5-Data-Dumper-2.07
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data

MAINTAINER=		packages@netbsd.org

USE_PERL5=		YES

WRKSRC=			${WRKDIR}/Data-Dumper-2.07
MAN3=			Data::Dumper.3
MANPREFIX=		${PREFIX}/lib/perl5

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
