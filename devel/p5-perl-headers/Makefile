# $NetBSD: Makefile,v 1.23 2005/05/07 22:00:35 jschauma Exp $

DISTNAME=		p5-perl-headers
PKGNAME=		${DISTNAME}-${OS_VERSION}
SVR4_PKGNAME=		p5plh
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://language.perl.com/index.html
COMMENT=		Perl header files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}
PERL5_PACKLIST=		${PERL5_INSTALLSITEARCH}/.packlist.h2ph

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
OSVERSION_SPECIFIC=     yes

# Since this package will be named, for instance, p5-perl-headers-1.5.1,
# binary packages on a FTP server (where only "1.5" is used as the directory
# name) will be ambiguous.  A user of 1.5 may mistakenly install the
# perl-headers-1.5.1 pkg by use of the automatic "best version" logic.

NO_BIN_ON_FTP=		FTP servers do not distinguish A.B.X revisions of versions

do-build:
	${MKDIR} ${WRKSRC}/h2ph
	${RM} -f ${WRKSRC}/h2ph_log ${WRKSRC}/packlist
	( cd /usr/include; \
	  ${BUILDLINK_PREFIX.perl}/bin/h2ph -d ${WRKSRC}/h2ph -r -l . ) \
		> ${WRKSRC}/h2ph_log
	( ${ECHO} "${PERL5_INSTALLSITEARCH}/_h2ph_pre.ph"; \
	  ${CAT} ${WRKSRC}/h2ph_log \
		| ${GREP} -- "->" \
		| ${SED} -e "s,.*\./,${PERL5_INSTALLSITEARCH}/,g" ) \
		| ${SORT} -u \
		> ${WRKSRC}/packlist

do-install:
	${INSTALL_DATA_DIR} ${PERL5_INSTALLSITEARCH}
	cd ${WRKSRC}/h2ph/ && ${PAX} -rw . ${PERL5_INSTALLSITEARCH}
	${INSTALL_DATA} ${WRKSRC}/packlist ${PERL5_PACKLIST}
	${CAT} ${PERL5_PACKLIST} | ${XARGS} ${CHMOD} a-w
	${CAT} ${PERL5_PACKLIST} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}

# empty do-nothing to override module.mk TEST_TARGET
do-test:

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
