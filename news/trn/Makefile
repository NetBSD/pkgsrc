# $NetBSD: Makefile,v 1.19 2005/06/20 01:57:36 kristerw Exp $

DISTNAME=		trn-4.0-test76
PKGNAME=		trn-4.76
PKGREVISION=		2
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=trn/} \
			ftp://trn.sourceforge.net/pub/trn/

MAINTAINER=     	tech-pkg@NetBSD.org
HOMEPAGE=		http://trn.sourceforge.net/
COMMENT=		Threaded version of rn, the classic news reader

LICENSE=		trn-license

PKG_SYSCONFSUBDIR=	nntp

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INN) && ${USE_INN} == YES
DEPENDS=		inn>=2.2:../inn
.else
DEPENDS=		nntpclnt>=1.6.1:../nntpclnt
.endif

# TRN_HOSTBITS determines the number of "name segments" (x.y.z.com), counting
# from right to left, that TRN will match to allow cancels, with 0 requiring
# a perfect match.  For example, with TRN_HOSTBITS=3, x.y.z.com will match
# foo.y.z.com for the purposes of allowing cancels.
TRN_HOSTBITS?=		0

USE_PERL5=		# defined

HAS_CONFIGURE=		# defined
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ENV=		PREFIX=${PREFIX}
USE_TOOLS+=		awk basename cat cp echo egrep expr grep mkdir mv
USE_TOOLS+=		rm sed tail tr
CONFIGURE_ENV+=		TOOLS_AWK="${TOOLS_AWK}"
CONFIGURE_ENV+=		TOOLS_BASENAME="${TOOLS_BASENAME}"
CONFIGURE_ENV+=		TOOLS_CAT="${TOOLS_CAT}"
CONFIGURE_ENV+=		TOOLS_CP="${TOOLS_CP}"
CONFIGURE_ENV+=		TOOLS_ECHO="${TOOLS_ECHO}"
CONFIGURE_ENV+=		TOOLS_EGREP="${TOOLS_EGREP}"
CONFIGURE_ENV+=		TOOLS_EXPR="${TOOLS_EXPR}"
CONFIGURE_ENV+=		TOOLS_GREP="${TOOLS_GREP}"
CONFIGURE_ENV+=		TOOLS_MKDIR="${TOOLS_MKDIR}"
CONFIGURE_ENV+=		TOOLS_MV="${TOOLS_MV}"
CONFIGURE_ENV+=		TOOLS_RM="${TOOLS_RM}"
CONFIGURE_ENV+=		TOOLS_SED="${TOOLS_SED}"
CONFIGURE_ENV+=		TOOLS_TAIL="${TOOLS_TAIL}"
CONFIGURE_ENV+=		TOOLS_TR="${TOOLS_TR}"
CONFIGURE_ARGS=		-d -e -D bin=${PREFIX}/bin \
			-D binexp=${PREFIX}/bin \
			-D phost=${PKG_SYSCONFDIR}'/domainname' \
			-D filexp=${PREFIX}'/share/trn/filexp' \
			-D hostbits=${TRN_HOSTBITS} \
			-D installbin=${PREFIX}'/bin' \
			-D installmansrc=${PREFIX}'/man/man1' \
			-D installprivlib=${PREFIX}'/share/trn' \
			-D libpth=${PREFIX}'/lib /usr/lib' \
			-D mansrc=${PREFIX}'/man/man1' \
			-D mansrcexp=${PREFIX}'/man/man1' \
			-D mimecap=${PREFIX}'/etc/mimecap' \
			-D orgname=${PKG_SYSCONFDIR}'/organization' \
			-D perl=${PERL5} \
			-D perlpath=${PERL5} \
			-D prefix=${PREFIX} \
			-D prefixexp=${PREFIX} \
			-D privlib=${PREFIX}'/share/trn' \
			-D privlibexp=${PREFIX}'/share/trn' \
			-D servername=${PKG_SYSCONFDIR}'/server' \
			-D d_nntp \
			-U d_local \
			-D libs=' ' \
			-D usevfork=false \
			-D inews=${PREFIX}'/bin/inews' \
			-D useinews=${PREFIX}'/bin/inews'

post-install:
	@${RM} -f ${PREFIX}/bin/rn ${PREFIX}/man/man1/rn.1 \
		${PREFIX}/man/man1/rn.1.gz
	@${LN} -s trn ${PREFIX}/bin/rn
	@${LN} -s trn.1 ${PREFIX}/man/man1/rn.1

.include "../../mk/bsd.pkg.mk"
