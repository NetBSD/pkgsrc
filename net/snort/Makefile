# $NetBSD: Makefile,v 1.14 2001/12/02 14:43:49 kleink Exp $
#

DISTNAME=	snort-1.8.3
CATEGORIES=	net security
MASTER_SITES=	http://www.snort.org/releases/				\
		ftp://the.wiretapped.net/pub/security/network-intrusion-detection/snort/ \
		http://www.centus.com/snort/				\
		http://snort.whitehats.com/				\
		http://snort.safenetworks.com/				\
		ftp://gd.tuwien.ac.at/infosys/security/snort/		\
		http://snort.sourcefire.com/releases/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.snort.org/
COMMENT=	Libpcap-based packet sniffer/logger

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-libpcap-includes=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-libpcap-libraries=${BUILDLINK_DIR}/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
ROOTGROUP=	root
.endif

ROOTGROUP?=	wheel

#WRKSRC=		${WRKDIR}/snort

post-install:
	${INSTALL_DATA_DIR} -m 700 -o root -g ${ROOTGROUP} /var/log/snort
	${INSTALL_DATA_DIR} ${PREFIX}/share/snort
	cd ${WRKSRC} ; \
	for i in snort.conf *.config *.rules ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/snort ; \
	done
	:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snort
	cd ${WRKSRC} ; \
	for f in [A-LN-Z]* ; do \
		${INSTALL_DATA} $$f ${PREFIX}/share/doc/snort ; \
	done
	:
	${INSTALL_DATA_DIR} ${PREFIX}/share/snort/MIBS
	cd ${WRKSRC}/MIBS ; \
	for m in SnortCommonMIB.txt SnortIDAlertMIB.txt ; do \
		${INSTALL_DATA} $$m ${PREFIX}/share/snort/MIBS ; \
	done
	${INSTALL_MAN} ${WRKSRC}/snort.8 ${PREFIX}/man/man8

.include "../../net/libpcap/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
