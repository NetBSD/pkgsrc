# $NetBSD: Makefile,v 1.12 2004/10/07 05:36:49 rh Exp $
#

DISTNAME=		ispman-0.5
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5isp
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ispman/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ispman.org/
COMMENT=		Perl module for ISPMan webAdministrator and command line utils

DEPENDS+=		{p5-CGI>=2.72,perl>=5.6.1nb2}:../../www/p5-CGI
DEPENDS+=		p5-Text-Template>=1.23:../../textproc/p5-Text-Template
DEPENDS+=		p5-perl-ldap>=0.22:../../databases/p5-perl-ldap
DEPENDS+=		p5-IMAP-Admin>=1.2.5:../../mail/p5-IMAP-Admin
DEPENDS+=		p5-Convert-ASN1>=0.07:../../textproc/p5-Convert-ASN1
DEPENDS+=		p5-IO-stringy>=1.213:../../devel/p5-IO-stringy

WRKSRC=			${WRKDIR}/ispman/Modules/ISPMan
USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/ISPMan/.packlist
PLIST_SRC=		${WRKDIR}/PLIST
PERL5_CONFIGURE_DIRS=	${WRKSRC} ${WRKSRC}/../IO-stringy-1.212_patched
BUILD_DIRS=		${PERL5_CONFIGURE_DIRS}
INSTALL_DIRS=		${WRKSRC}

MAKE_PARAMS+=		--noprompt

pre-configure:
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	cd ${WRKSRC} &&							\
	for i in `${FIND} * -type f -print` ; do			\
		${CP} $$i $$i.old &&					\
		${SED} < $$i.old > $$i -e 's:/etc:${PREFIX}/etc:g' &&	\
		${RM} $$i.old ;						\
	done

post-build:
	${ECHO} >> ${PLIST_SRC}						\
	"`${GREP} ^INSTALLSITELIB					\
	   ${WRKSRC}/../IO-stringy-1.212_patched/Makefile		\
	   | ${CUT} -d/ -f2-`/IO/ScalarPatched.pm"

post-install:
	${INSTALL_DATA} ${WRKSRC}/../IO-stringy-1.212_patched/lib/IO/Scalar.pm \
		${PREFIX}/`${TAIL} -n 1 ${PLIST_SRC}`

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
