# $NetBSD: Makefile,v 1.6 2000/08/27 10:37:02 jlam Exp $

DISTNAME=		perl5.004_04
PKGNAME=		p5-gdbm-5.4.4
CATEGORIES=		databases perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org

DEPENDS+=		gdbm>=1.7.3:../../databases/gdbm

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GDBM_File/.packlist
EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
