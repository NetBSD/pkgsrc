# $NetBSD: Makefile,v 1.25 2005/12/01 19:45:11 wiz Exp $

DISTNAME=		trn-4.0-test76
PKGNAME=		trn-4.76
PKGREVISION=		3
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=trn/} \
			ftp://trn.sourceforge.net/pub/trn/

MAINTAINER=     	tech-pkg@NetBSD.org
HOMEPAGE=		http://trn.sourceforge.net/
COMMENT=		Threaded version of rn, the classic news reader

LICENSE=		trn-license

PKG_SYSCONFSUBDIR=	nntp

.include "options.mk"

# TRN_HOSTBITS determines the number of "name segments" (x.y.z.com), counting
# from right to left, that TRN will match to allow cancels, with 0 requiring
# a perfect match.  For example, with TRN_HOSTBITS=3, x.y.z.com will match
# foo.y.z.com for the purposes of allowing cancels.
TRN_HOSTBITS?=		0

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q}
USE_TOOLS+=		awk basename cat cp diff echo egrep expr grep mkdir mv
USE_TOOLS+=		perl:run rm sed tail tr
CONFIGURE_ENV+=		TOOLS_AWK=${TOOLS_AWK:Q}
CONFIGURE_ENV+=		TOOLS_BASENAME=${TOOLS_BASENAME:Q}
CONFIGURE_ENV+=		TOOLS_CAT=${TOOLS_CAT:Q}
CONFIGURE_ENV+=		TOOLS_CP=${TOOLS_CP:Q}
CONFIGURE_ENV+=		TOOLS_DIFF=${TOOLS_DIFF:Q}
CONFIGURE_ENV+=		TOOLS_ECHO=${TOOLS_ECHO:Q}
CONFIGURE_ENV+=		TOOLS_EGREP=${TOOLS_EGREP:Q}
CONFIGURE_ENV+=		TOOLS_EXPR=${TOOLS_EXPR:Q}
CONFIGURE_ENV+=		TOOLS_GREP=${TOOLS_GREP:Q}
CONFIGURE_ENV+=		TOOLS_MKDIR=${TOOLS_MKDIR:Q}
CONFIGURE_ENV+=		TOOLS_MV=${TOOLS_MV:Q}
CONFIGURE_ENV+=		TOOLS_RM=${TOOLS_RM:Q}
CONFIGURE_ENV+=		TOOLS_SED=${TOOLS_SED:Q}
CONFIGURE_ENV+=		TOOLS_TAIL=${TOOLS_TAIL:Q}
CONFIGURE_ENV+=		TOOLS_TR=${TOOLS_TR:Q}
CONFIGURE_ARGS+=	-d -e -D bin=${PREFIX:Q}/bin \
			-D binexp=${PREFIX:Q}/bin \
			-D phost=${PKG_SYSCONFDIR}'/domainname' \
			-D filexp=${PREFIX:Q}'/share/trn/filexp' \
			-D hostbits=${TRN_HOSTBITS:Q} \
			-D installbin=${PREFIX:Q}'/bin' \
			-D installmansrc=${PREFIX:Q}'/man/man1' \
			-D installprivlib=${PREFIX:Q}'/share/trn' \
			-D libpth=${PREFIX:Q}'/lib /usr/lib' \
			-D mansrc=${PREFIX:Q}'/man/man1' \
			-D mansrcexp=${PREFIX:Q}'/man/man1' \
			-D mimecap=${PREFIX:Q}'/etc/mimecap' \
			-D orgname=${PKG_SYSCONFDIR}'/organization' \
			-D perl=${PERL5:Q} \
			-D perlpath=${PERL5:Q} \
			-D prefix=${PREFIX:Q} \
			-D prefixexp=${PREFIX:Q} \
			-D privlib=${PREFIX:Q}'/share/trn' \
			-D privlibexp=${PREFIX:Q}'/share/trn' \
			-D servername=${PKG_SYSCONFDIR}'/server' \
			-D d_nntp \
			-U d_local \
			-D libs=' ' \
			-D usevfork=false \
			-D inews=${PREFIX:Q}'/bin/inews' \
			-D useinews=${PREFIX:Q}'/bin/inews'

post-install:
	@${RM} -f ${PREFIX}/bin/rn ${PREFIX}/man/man1/rn.1 \
		${PREFIX}/man/man1/rn.1.gz
	@${LN} -s trn ${PREFIX}/bin/rn
	@${LN} -s trn.1 ${PREFIX}/man/man1/rn.1

.include "../../mk/bsd.pkg.mk"
