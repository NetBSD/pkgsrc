# $NetBSD: Makefile,v 1.7 2001/02/17 18:19:38 wiz Exp $
#

DISTNAME=	snort-1.6.3-patch2
PKGNAME=	${DISTNAME:S/-patch/./}
CATEGORIES=	net security
MASTER_SITES=	http://www.snort.org/Files/				\
		ftp://the.wiretapped.net/pub/security/network-intrusion-detection/snort/ \
		http://www.centus.com/snort/				\
		http://snort.whitehats.com/				\
		http://snort.safenetworks.com/				\
		ftp://gd.tuwien.ac.at/infosys/security/snort/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.snort.org/
COMMENT=	Libpcap-based packet sniffer/logger

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
.for f in backdoor-lib ddos-lib finger-lib ftp-lib misc-lib netbios-lib \
	overflow-lib ping-lib rpc-lib scan-lib smtp-lib snort-lib telnet-lib \
	webcf-lib webcgi-lib webfp-lib webiis-lib webmisc-lib
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/snort
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snort
.for f in BUGS CREDITS README README.FLEXRESP README.PLUGINS NEWS	\
	RULES.SAMPLE USAGE
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/snort
.endfor
	${INSTALL_MAN} ${WRKSRC}/snort.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
