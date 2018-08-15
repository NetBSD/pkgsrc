# $NetBSD: Makefile,v 1.4 2018/08/15 17:49:22 schmonz Exp $

DISTNAME=		ucspi-tcp6-1.06
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		https://www.fehcom.de/ipnet/ucspi-tcp6/
EXTRACT_SUFX=		.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.fehcom.de/ipnet/ucspi-tcp6.html
COMMENT=		Command-line tools for building TCP client-server applications
LICENSE=		public-domain

CONFLICTS+=		ucspi-tcp-[0-9]*

WRKSRC=			${WRKDIR}/host/${PKGNAME_NOREV}
DJB_SLASHPACKAGE=	yes
DJB_RESTRICTED=		no
DJB_CONFIG_DIR=		${WRKSRC}

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.prefs.mk"

.if !defined(MANZ)
SUBST_CLASSES+=		manz
SUBST_STAGE.manz=	do-configure
SUBST_FILES.manz=	package/man
SUBST_SED.manz=		-e 's|safe gzip |safe true |g'
SUBST_SED.manz+=	-e 's|\.gz||g'
.endif

post-configure:
	${RUN}cd ${DJB_CONFIG_DIR};		\
	${ECHO} ${PKGMANDIR} > conf-man;	\
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
	./package/man

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
