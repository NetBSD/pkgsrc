# $NetBSD: Makefile,v 1.14 2001/01/29 11:34:37 wiz Exp $
#

DISTNAME=	ntp-4.0.99k
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/ \
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http://www.ntp.org/

DEPENDS+=	readline-4.*:../../devel/readline

GNU_CONFIGURE=	YES

CONFIGURE_ENV+=	"LIBS=-ltermcap"	# for ntpdc

DOCDIR=		${PREFIX}/share/doc
EXAMPLESDIR=	${PREFIX}/share/examples

post-install:
	cd ${WRKSRC}; \
	    ${RM} html/.cvsignore* 2> /dev/null || ${TRUE}; \
	    ${PAX} -r -w -s "/html/ntp4/" html ${DOCDIR}; \
	    ${PAX} -r -w -s "/conf/ntp4/" conf ${EXAMPLESDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}/ntp4 ${EXAMPLESDIR}/ntp4
	${CHMOD} -R ${SHAREMODE} ${DOCDIR}/ntp4 ${EXAMPLESDIR}/ntp4
	${CHMOD} a+x ${DOCDIR}/ntp4 ${DOCDIR}/ntp4/hints ${DOCDIR}/ntp4/pic
	${CHMOD} a+x ${EXAMPLESDIR}/ntp4

.include "../../mk/bsd.pkg.mk"
