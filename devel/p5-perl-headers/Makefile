# $NetBSD: Makefile,v 1.10 2001/11/26 06:49:56 jlam Exp $

DISTNAME=		p5-perl-headers
PKGNAME=		${DISTNAME}-${OS_VERSION}
SVR4_PKGNAME=		p5plh
CATEGORIES=		devel perl5
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html
COMMENT=		Perl header files

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/.packlist.h2ph

EXTRACT_ONLY=		# empty
WRKSRC=			${WRKDIR}
NO_CHECKSUM=		# defined
NO_PATCH=		# defined

# Since this package will be named, for instance, p5-perl-headers-1.5.1,
# binary packages on a FTP server (where only "1.5" is used as the directory
# name) will be ambiguous.  A user of 1.5 may mistakenly install the
# perl-headers-1.5.1 pkg by use of the automatic "best version" logic.

NO_BIN_ON_FTP=		FTP servers do not distinguish A.B.X revisions of versions

do-build:
	${MKDIR} ${WRKSRC}/h2ph
	${RM} -f ${WRKSRC}/h2ph_log ${WRKSRC}/packlist
	( cd /usr/include; ${PREFIX}/bin/h2ph -d ${WRKSRC}/h2ph -r -l . ) \
		> ${WRKSRC}/h2ph_log
	( ${ECHO} "${PERL5_SITEARCH}/_h2ph_pre.ph"; \
	  ${CAT} ${WRKSRC}/h2ph_log \
		| ${GREP} -- "->" \
		| ${SED} -e "s,.*\./,${PERL5_SITEARCH}/,g" ) \
		| ${SORT} -u \
		> ${WRKSRC}/packlist

do-install:
	${INSTALL_DATA_DIR} ${PERL5_SITEARCH}
	${CP} -R ${WRKSRC}/h2ph/* ${PERL5_SITEARCH}
	${INSTALL_DATA} ${WRKSRC}/packlist ${PERL5_PACKLIST}
	${CAT} ${PERL5_PACKLIST} | ${XARGS} ${CHMOD} a-w
	${CAT} ${PERL5_PACKLIST} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
