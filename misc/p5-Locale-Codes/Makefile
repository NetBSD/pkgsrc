# $NetBSD: Makefile,v 1.4 1998/04/20 11:56:28 frueauf Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/06/27 01:51:12 jfitz Exp
#

DISTNAME=		Locale-Codes-0.003
PKGNAME=		p5-Locale-Codes-0.003
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Locale

MAINTAINER=		packages@netbsd.org

USE_PERL5=		YES

MANPREFIX=		${PREFIX}/lib/perl5
MAN3=			Locale::Country.3 Locale::Language.3

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
