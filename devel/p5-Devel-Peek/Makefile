# $NetBSD: Makefile,v 1.3 2000/08/29 19:19:45 jlam Exp $
#

DISTNAME=		perl-5.6.0
PKGNAME=		p5-Devel-Peek-1.0001
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/} \
			ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org

# Needs at least perl-5.6.0 to build, and versions older than 5.6.0nb1
# had their own version of Devel::Peek.
DEPENDS+=		perl>=5.6.0nb1:../../lang/perl5-current

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/Peek/.packlist
EXTRACT_ELEMENTS=	${DISTNAME}/ext/Devel/Peek
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
