# $NetBSD: Makefile,v 1.21 2002/07/16 14:57:08 fredb Exp $
#

DISTNAME=	ntp-4.1.1a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/ \
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.ntp.org/
COMMENT=	Network Time Protocol Version 4

GNU_CONFIGURE=	YES

CONFIGURE_ENV+=	PATH_PERL="${PERL5}"
CONFIGURE_ENV+=	ac_cv_lib_readline_readline=no

DOCDIR=		${PREFIX}/share/doc/html
EXAMPLESDIR=	${PREFIX}/share/examples

pre-configure:
	cd ${WRKSRC} &&						\
	    ${TOUCH} stamp-h.in COPYRIGHT			\
		    `${FIND} . -name aclocal.m4 -print`		\
		    `${FIND} . -name configure -print`		\
		    `${FIND} . -name Makefile.in -print`

post-install:
	cd ${WRKSRC} &&						\
	    ${RM} conf/.cvsignore* 2> /dev/null || ${TRUE};	\
	    ${RM} html/.cvsignore* 2> /dev/null || ${TRUE};	\
	    ${PAX} -r -w -s "/html/ntp4/" html ${DOCDIR};	\
	    ${PAX} -r -w -s "/conf/ntp4/" conf ${EXAMPLESDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}/ntp4 ${EXAMPLESDIR}/ntp4
	${CHMOD} -R ${SHAREMODE} ${DOCDIR}/ntp4 ${EXAMPLESDIR}/ntp4
	${CHMOD} a+x ${DOCDIR}/ntp4 ${DOCDIR}/ntp4/hints ${DOCDIR}/ntp4/pic
	${CHMOD} a+x ${EXAMPLESDIR}/ntp4

.include "../../mk/bsd.pkg.mk"
