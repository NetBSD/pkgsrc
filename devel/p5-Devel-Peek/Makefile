# $NetBSD: Makefile,v 1.1.1.1 2000/08/27 21:33:39 jlam Exp $
#

DISTNAME=		perl-5.6.0
PKGNAME=		p5-Devel-Peek-1.0001
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/} \
			ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org

CONFLICTS=		perl-5.6.0	# needs perl>5.6.0 or perl-5.00*

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/Peek/.packlist
EXTRACT_ELEMENTS=	${DISTNAME}/ext/Devel/Peek
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
