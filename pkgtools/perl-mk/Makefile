# $NetBSD: Makefile,v 1.3 2001/04/22 06:25:18 jlam Exp $
#

DISTNAME=	perl-mk-1.1
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wiz@netbsd.org
COMMENT=	Note installed perl version for bsd.pkg.mk speedup

# for backwards compatibility, and since we want to be included by the
# perl meta-package, we can't just use USE_PERL5
DEPENDS+=	perl-{5.0*,5.6.0nb[12],base-5.[6-9]*}:../../lang/perl5-base

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_PATCH=	# defined
NO_BUILD=	# defined

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

pre-install:
	${SED}	-e "s|@RM@|${RM}|g"					\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s|@RM@|${RM}|g"					\
		-e "s|@PERL5@|${PERL5}|g"				\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}

# The argument to the INSTALL script is misnamed in this case.  We are
# actually installing a bsd.perl.mk file, but we'd like to generate it at
# install-time to ensure that the values for the various PERL5_* variables
# are consistent with the installed Perl version.  But there is no "INSTALL"
# target for the INSTALL script, so do the work in the "POST-INSTALL" target.
#
do-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
