# $NetBSD: Makefile,v 1.26 2003/11/01 00:52:50 kristerw Exp $
#

DISTNAME=	ntp-4.2.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/		\
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.ntp.org/
COMMENT=	Network Time Protocol Version 4

GNU_CONFIGURE=	YES
USE_PERL5=	build
#USE_BUILDLINK2=YES ***FIXME: Causes lots of "missing prototype" warnings.***

CONFIGURE_ENV+=	PATH_PERL="${PERL5}"

DOCDIR=		${PREFIX}/share/doc/html
EXAMPLESDIR=	${PREFIX}/share/examples

post-install:
	cd ${WRKSRC} &&						\
	    ${RM} conf/.cvsignore* 2> /dev/null || ${TRUE};	\
	    ${RM} html/.cvsignore* 2> /dev/null || ${TRUE};	\
	    ${PAX} -rw -s "/html/ntp4/" html ${DOCDIR};		\
	    ${PAX} -rw -s "/conf/ntp4/" conf ${EXAMPLESDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}/ntp4 ${EXAMPLESDIR}/ntp4
	${CHMOD} -R ${SHAREMODE} ${DOCDIR}/ntp4 ${EXAMPLESDIR}/ntp4
	${CHMOD} a+x ${DOCDIR}/ntp4 ${DOCDIR}/ntp4/hints ${DOCDIR}/ntp4/pic
	${CHMOD} a+x ${EXAMPLESDIR}/ntp4

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
#
# Use POSIX nanosecond timers when available, but not otherwise.
#
LOWER_OPSYS_VERSUFFIX=	1
MACHINE_GNU_PLATFORM=	${LOWER_ARCH}--${LOWER_OPSYS}${LOWER_OPSYS_VERSUFFIX}
. for __wildcard__ in 1.6[N-Z]* 2*
.  if ${OS_VERSION:M${__wildcard__}} != ""
LOWER_OPSYS_VERSUFFIX=	2
.  endif
. endfor
#
# Don't pick up libwww's -lmd5, until buildlink can be fixed.
#
CONFIGURE_ENV+=	ac_cv_lib_md5_MD5Init=no
.endif

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
