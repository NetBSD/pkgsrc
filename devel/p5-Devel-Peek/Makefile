# $NetBSD: Makefile,v 1.7 2001/02/26 07:23:57 jlam Exp $
#

DISTNAME=		perl-5.6.0
PKGNAME=		p5-Devel-Peek-1.0001
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/} \
			ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module containing a data debugging tool for XS programmers

# Some perl packages install their own versions of this module.
# Can't simply define USE_PERL5.
DEPENDS+=		perl-{5.0*,5.6.0nb2,base-5.[6-9]*}:../../lang/perl5-base

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/Peek/.packlist
EXTRACT_ELEMENTS=	${DISTNAME}/ext/Devel/Peek
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"

.if !defined(PERL5_SITEARCH)
PERL5_SITEARCH!=	eval `${PERL5} -V:installsitearch 2>/dev/null`; \
			${ECHO} $${installsitearch}
.endif
