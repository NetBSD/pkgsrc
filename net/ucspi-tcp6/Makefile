# $NetBSD: Makefile,v 1.26 2020/07/31 19:05:50 schmonz Exp $

DISTNAME=		ucspi-tcp6-1.11.5
CATEGORIES=		net sysutils
MASTER_SITES=		https://www.fehcom.de/ipnet/ucspi-tcp6/
EXTRACT_SUFX=		.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.fehcom.de/ipnet/ucspi-tcp6.html
COMMENT=		Command-line tools for building TCP client-server applications
LICENSE=		public-domain

CONFLICTS+=		ucspi-tcp-[0-9]*

WRKSRC=			${WRKDIR}/net/${PKGBASE}/${DISTNAME}
DJB_SLASHPACKAGE=	yes
DJB_RESTRICTED=		no
DJB_CONFIG_DIR=		${WRKSRC}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

MAKE_JOBS_SAFE=		no

post-configure:
	${RUN}cd ${DJB_CONFIG_DIR};		\
	${MKDIR} compile;			\
	${ECHO} ${DJB_CONFIG_PREFIX}/bin > compile/home

do-install:
	cd ${WRKSRC};							\
	for i in addcr argv0 delcr fixcrio mconnect-io rblsmtpd		\
		recordio tcpclient tcprules tcprulescheck tcpserver; do	\
	  ${INSTALL_PROGRAM} command/$${i} ${DESTDIR}${PREFIX}/bin;	\
	done;								\
	for i in date@ finger@ http@ mconnect tcpcat who@; do		\
	  ${INSTALL_SCRIPT} command/$${i} ${DESTDIR}${PREFIX}/bin;	\
	done;								\
	for i in *.1; do						\
	  ${INSTALL_MAN} man/$${i} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/;\
	done;								\
	for i in *.5; do						\
	  ${INSTALL_MAN} man/$${i} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/;\
	done

.include "../../net/fehqlibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
