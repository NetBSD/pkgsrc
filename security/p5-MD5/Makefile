# $NetBSD: Makefile,v 1.5 1998/04/20 11:56:32 frueauf Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:23 jfitz Exp
#

DISTNAME=		MD5-1.7
PKGNAME=		p5-MD5-1.7
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MD5

MAINTAINER=		packages@netbsd.org

USE_PERL5=		YES

MAN3=			MD5.3
MANPREFIX=		${PREFIX}/lib/perl5

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
