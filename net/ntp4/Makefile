# $NetBSD: Makefile,v 1.13 2000/08/18 19:39:53 fredb Exp $
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
MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-build:
	${SED} 's|@PREFIX@|${PREFIX}|g' < ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

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
