# $NetBSD: Makefile,v 1.10 2001/02/16 14:17:34 wiz Exp $

DISTNAME=		perl-5.6.0
PKGNAME=		p5-gdbm-1.03
CATEGORIES=		databases perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org
COMMENT=		perl interface to gdbm - GNU database manager

DEPENDS+=		gdbm>=1.7.3:../../databases/gdbm
DEPENDS+=		perl>=5.6.0:../../lang/perl5

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GDBM_File/.packlist
EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
