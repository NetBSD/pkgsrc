# $NetBSD: Makefile,v 1.5 2000/03/20 12:03:45 agc Exp $
#

DISTNAME=	snort-1.6
CATEGORIES=	net security
MASTER_SITES=	http://www.clark.net/~roesch/ \
		ftp://the.wiretapped.net/pub/security/network-intrusion-detection/snort/ \
		http://www.centus.com/snort/ \
		http://snort.whitehats.com/ \
		http://snort.safenetworks.com/ \
		ftp://gd.tuwien.ac.at/infosys/security/snort/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.clark.net/~roesch/security.html

GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS=	libpcap-0.4:../../net/libpcap
ROOTGROUP=	root
.endif

ROOTGROUP?=	wheel

post-install:
	${INSTALL_DATA_DIR} -m 700 -o root -g ${ROOTGROUP} /var/log/snort
	${INSTALL_DATA_DIR} ${PREFIX}/share/snort
.for f in backdoor-lib misc-lib overflow-lib scan-lib snort-lib web-lib
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/snort
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snort
.for f in README README.PLUGINS NEWS RULES.SAMPLE USAGE
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/snort
.endfor
	${INSTALL_MAN} ${WRKSRC}/snort.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
