# $NetBSD: Makefile,v 1.3 2000/08/24 08:20:44 jlam Exp $
#

DISTNAME=	eperl-2.2.14
CATEGORIES=	lang perl5 textproc
MASTER_SITES=	http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.engelschall.com/sw/eperl/

BUILD_DEPENDS+=	autoreconf:../../devel/autoconf
DEPENDS=	libperl-5.*:../../lang/libperl

USE_PERL5=	# defined
PERL=		${LOCALBASE}/bin/perl
P5_PACKLIST=	${P5_SITEARCH}/auto/Parse/ePerl/.packlist

GNU_CONFIGURE=	# defined
ALL_TARGET=	all libeperl.a

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

pre-configure:
	cd ${WRKSRC} && autoreconf

post-build:
	cd ${WRKSRC}/mod/Parse && ${PERL} Makefile.PL && ${MAKE}

post-install:
	cd ${WRKSRC}/mod/Parse && ${MAKE} install
	${RM} -f ${PLIST_SRC}
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	#
	# Add the installed files to the PLIST.
	#
	( ${CAT} ${P5_PACKLIST}; for f in ${P5_PACKLIST}; do echo $$f; done ) \
		| ${SED} -e "s,/./,/,g" -e "s,${PREFIX}/,," \
		| sort -u \
		>> ${PLIST_SRC}
	#
	# We're not sure which directories are empty and can be deleted, so
	# try them all, but ignore failures.
	#
	( ${CAT} ${P5_PACKLIST}; for f in ${P5_PACKLIST}; do echo $$f; done ) \
		| ${SED} -e "s,/./,/,g" -e "s,${PREFIX}/,," \
			-e "s,^,@unexec rmdir -p %D/," \
			-e "s,/[^/]*$$, 2>/dev/null || true," \
		| sort -ur \
		>> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"

P5_SITEARCH!=	eval `${PERL} -V:installsitearch`; echo $${installsitearch}
