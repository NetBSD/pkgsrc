# $NetBSD: Makefile,v 1.4 2000/02/16 18:47:15 wiz Exp $
#

DISTNAME=		trn4-test72
PKGNAME=		trn-4.test72
CATEGORIES=		news
MASTER_SITES=		http://www.clari.net/~wayne/

MAINTAINER=     	drankin@bohemians.lexington.ky.us
HOMEPAGE=		http://www.clari.net/~wayne/

.include "../../mk/bsd.prefs.mk"

# Normally, one or more of the following variables will be set inside 
# of /etc/mk.conf before build time.  Names of local hierarchies, e.g.
# at, aus, or de,  or even smaller areas. Only changes a warning in
# inews.
TRN_LOCAL_ORG_DISTRIBUTION?=	none
TRN_ORG_DISTRIBUTION?=		none
TRN_CITY_DISTRIBUTION?=		none
TRN_COUNTRY_DISTRIBUTION?=	none
TRN_REGION_DISTRIBUTION?=	none
TRN_CONTINENT_DISTRIBUTION?=	none

# TRN_HOSTBITS determines the number of "name segments" (x.y.z.com), counting
# from right to left, that TRN will match to allow cancels, with 0 requiring
# a perfect match.  For example, with TRN_HOSTBITS=3, x.y.z.com will match
# foo.y.z.com for the purposes of allowing cancels.
TRN_HOSTBITS?=			0

#TRN_ORGANIZATION defines the value for the "Organization" header in inews.
TRN_ORGANIZATION?=		none

# The following variables must be set for proper function, but TRN does
# not set sane default values due to the inherant dangers involved.
.if !defined(TRN_DOMAINNAME)
    || !defined(TRN_NNTPSERVER)
IS_INTERACTIVE=		yes
.endif

USE_PERL5=		yes

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ENV=		PREFIX=${PREFIX}
CONFIGURE_ARGS=		-d -e -D bin=${PREFIX}/bin \
		-D binexp=${PREFIX}/bin \
		-D phost="`${CAT} ${WRKDIR}/.trn_domainname`" \
		-D citydist=${TRN_CITY_DISTRIBUTION} \
		-D cntrydist=${TRN_COUNTRY_DISTRIBUTION} \
		-D contdist=${TRN_CONTINENT_DISTRIBUTION} \
		-D filexp=${PREFIX}'/libdata/trn/filexp' \
		-D hostbits=${TRN_HOSTBITS} \
		-D installbin=${PREFIX}'/bin' \
		-D installinews=${PREFIX}'/libexec/trn/inews' \
		-D installmansrc=${PREFIX}'/man/man1' \
		-D installprivlib=${PREFIX}'/libdata/trn' \
		-D libpth=${PREFIX}'/lib /usr/lib' \
		-D locdist=${TRN_LOCAL_ORG_DISTRIBUTION} \
		-D mansrc=${PREFIX}'/man/man1' \
		-D mansrcexp=${PREFIX}'/man/man1' \
		-D mimecap=${PREFIX}'/etc/mimecap' \
		-D multistatedist=${TRN_REGION_DISTRIBUTION} \
		-D orgdist=${TRN_ORG_DISTRIBUTION} \
		-D orgname=${PREFIX}'/libdata/trn/organization' \
		-D perl=${PREFIX}'/bin/perl' \
		-D perlpath=${PREFIX}'/bin/perl' \
		-D prefix=${PREFIX} \
		-D prefixexp=${PREFIX} \
		-D privlib=${PREFIX}'/libdata/trn' \
		-D privlibexp=${PREFIX}'/libdata/trn' \
		-D servername=${PREFIX}'/libdata/trn/nntpserver' \
		-D d_nntp -U d_local -D libs=' ' -D usevfork=false
#		-D inews=${PREFIX}'/libexec/trn/inews' \
#		-D useinews=${PREFIX}'/libexec/trn/inews' \

pre-configure:
	if [ "${TRN_DOMAINNAME}" = "" ]; then \
		${ECHO} "TRN_DOMAINNAME must be set. This variable tells trn what hostname to" ;\
		${ECHO} "place on the From: line during postings. You can:" ;\
		${ECHO} "1.  Choose a static hostname, such as your domain (which will match" ;\
		${ECHO} "    your sub-domain machines as well) and enter it here." ;\
		${ECHO} "2.  Specify just the domain portion (by starting the name with a '.')" ;\
		${ECHO} "    and your machine name will be computed at runtime and this domain" ;\
		${ECHO} "    appended to the end." ;\
		${ECHO} "3.  Enter just a '.' to have the machine AND domain computed at runtime." ;\
		${ECHO} ;\
		${ECHO} -n "Domainname: " ; \
		read TRN_DOMAINNAME ;\
		${ECHO} ;\
	else \
		TRN_DOMAINNAME=${TRN_DOMAINNAME} ; \
	fi; \
	${ECHO} -n $$TRN_DOMAINNAME > ${WRKDIR}/.trn_domainname

pre-install:
	@${MKDIR} ${PREFIX}/libexec/trn

post-install:
	@if [ "${TRN_NNTPSERVER}" = "" ]; then \
		${ECHO} "TRN_NNTPSERVER must be set. This variable tells trn what hostname to" ;\
		${ECHO} "use as the initial default NNTP server. After installation, this" ;\
		${ECHO} "value can be changed by editing ${PREFIX}/libdata/trn/nntpserver" ;\
		${ECHO} ;\
		${ECHO} -n "NNTP server: " ; \
		read TRN_NNTPSERVER ; \
		${ECHO} ;\
	else \
		TRN_NNTPSERVER=${TRN_NNTPSERVER} ; \
	fi; \
	${ECHO} $$TRN_NNTPSERVER > ${PREFIX}/libdata/trn/nntpserver
	@${ECHO} ${TRN_ORGANIZATION} > ${PREFIX}/libdata/trn/organization
	@${RM} -f ${PREFIX}/bin/rn ${PREFIX}/man/man1/rn.1 ${PREFIX}/man/man1/rn.1.gz
	@${LN} -s trn ${PREFIX}/bin/rn
	@${LN} -s trn.1 ${PREFIX}/man/man1/rn.1

.include "../../mk/bsd.pkg.mk"
