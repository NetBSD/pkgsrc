# $NetBSD: Makefile,v 1.1.1.1 2001/02/20 16:23:55 wiz Exp $
#

DISTNAME=	perl-mk-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wiz@netbsd.org
COMMENT=	Note installed perl version for bsd.pkg.mk speedup

# for backwards compatibility, and since we want to be included by the
# perl meta-package, we can't just use USE_PERL
DEPENDS+=	perl-{5.0*,5.6.0nb[12],base-5.[6-9]*}:../../lang/perl5-base

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_PATCH=	# defined
NO_BUILD=	# defined

MKPATH=		${PREFIX}/share/mk
PLIST_SUBST+=	MKPATH="share/mk"

do-install:
	${ECHO} PERL5_SITELIB=${PERL5_SITELIB} > ${MKPATH}/bsd.perl.mk
	${ECHO} PERL5_SITEARCH=${PERL5_SITEARCH} >> ${MKPATH}/bsd.perl.mk
	${ECHO} PERL5_ARCHLIB=${PERL5_ARCHLIB} >> ${MKPATH}/bsd.perl.mk

.include "../../mk/bsd.pkg.mk"

# needs PERL5 defined from bsd.pkg.mk
PERL5_SITELIB!=		eval `${PERL5} -V:installsitelib 2>/dev/null`; \
			${ECHO} $${installsitelib}
PERL5_SITEARCH!=	eval `${PERL5} -V:installsitearch 2>/dev/null`; \
			${ECHO} $${installsitearch}
PERL5_ARCHLIB!=		eval `${PERL5} -V:installarchlib 2>/dev/null`; \
			${ECHO} $${installarchlib}
