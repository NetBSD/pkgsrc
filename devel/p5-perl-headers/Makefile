# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 07:35:14 jlam Exp $

DISTNAME=		p5-perl-headers
PKGNAME=		${DISTNAME}-${OS_VERSION}
CATEGORIES=		devel perl5
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/.packlist.h2ph

EXTRACT_ONLY=		# empty
NO_WRKSUBDIR=		# defined
NO_CHECKSUM=		# defined
NO_PATCH=		# defined
NO_CONFIGURE=		# defined

do-build:
	${MKDIR} -p ${WRKSRC}/h2ph
	${RM} -f ${WRKSRC}/h2ph_log ${WRKSRC}/packlist
	( cd /usr/include; ${PREFIX}/bin/h2ph -d ${WRKSRC}/h2ph -r -l . ) \
		> ${WRKSRC}/h2ph_log
	( ${ECHO} "${PERL5_SITEARCH}/_h2ph_pre.ph"; \
	  ${CAT} ${WRKSRC}/h2ph_log \
		| ${GREP} -- "->" \
		| ${SED} -e "s,.*\./,${PERL5_SITEARCH}/,g" ) \
		| sort -u \
		> ${WRKSRC}/packlist

do-install:
	${CP} -R ${WRKSRC}/h2ph/* ${PERL5_SITEARCH}
	${INSTALL_DATA} ${WRKSRC}/packlist ${PERL5_PACKLIST}
	${CAT} ${PERL5_PACKLIST} | xargs chmod a-w
	${CAT} ${PERL5_PACKLIST} | xargs chown ${SHAREOWN}:${SHAREGRP}

.include "../../mk/bsd.pkg.mk"
