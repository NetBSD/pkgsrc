# $NetBSD: Makefile,v 1.5 2000/06/13 10:40:24 wiz Exp $

DISTNAME=		perl5.004_04
PKGNAME=		p5-gdbm-5.4.4
CATEGORIES=		databases perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org

DEPENDS+=		gdbm>=1.7.3:../../databases/gdbm

USE_PERL5=		YES
EXTRACT_ELEMENTS=	perl5.004_04/ext/GDBM_File
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
