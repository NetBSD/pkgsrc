# $NetBSD: Makefile,v 1.6 2001/11/26 06:50:13 jlam Exp $
#

DISTNAME=		ispman-0.5
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5isp
WRKSRC=			${WRKDIR}/ispman/Modules/ISPMan
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ispman/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.ispman.org/
COMMENT=		Perl module for ISPMan webAdministrator and command line utils

DEPENDS+=		{p5-CGI>=2.72,perl>=5.6.1nb2}:../../www/p5-CGI
DEPENDS+=		p5-Text-Template>=1.23:../../textproc/p5-Text-Template
DEPENDS+=		p5-perl-ldap>=0.22:../../databases/p5-perl-ldap
DEPENDS+=		p5-IMAP-Admin>=1.2.5:../../mail/p5-IMAP-Admin
DEPENDS+=		p5-Convert-ASN1>=0.07:../../textproc/p5-Convert-ASN1
DEPENDS+=		p5-IO-stringy>=1.213:../../devel/p5-IO-stringy

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/ISPMan/.packlist
PLIST_SRC=		${WRKDIR}/PLIST

MAKE_PARAMS+=		--noprompt

do-configure:
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	cd ${WRKSRC} &&							\
	for i in `${FIND} * -type f -print` ; do			\
		${CP} $$i $$i.old &&					\
		${SED} < $$i.old > $$i -e 's:/etc:${PREFIX}/etc:g' &&	\
		${RM} $$i.old ;						\
	done &&								\
	${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}
	cd ${WRKSRC}/../IO-stringy-1.212_patched &&			\
	${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

post-build:
	cd ${WRKSRC}/../IO-stringy-1.212_patched &&			\
	${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET} && 			\
	${ECHO} >> ${PLIST_SRC}						\
	"`${GREP} ^INSTALLSITELIB Makefile | ${CUT} -d/ -f2-`/IO/ScalarPatched.pm"

post-install:
	${INSTALL_DATA} ${WRKSRC}/../IO-stringy-1.212_patched/lib/IO/Scalar.pm \
		${PREFIX}/`${TAIL} -n 1 ${PLIST_SRC}`

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
