# $NetBSD: Makefile,v 1.9 2001/08/03 06:35:11 itojun Exp $
#

DISTNAME=	snort-1.8p1
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
DEPENDS+=	libpcap-0.4:../../net/libpcap
ROOTGROUP=	root
.endif

ROOTGROUP?=	wheel

WRKSRC=		${WRKDIR}/snort

post-install:
	${INSTALL_DATA_DIR} -m 700 -o root -g ${ROOTGROUP} /var/log/snort
	${INSTALL_DATA_DIR} ${PREFIX}/share/snort
.for f in backdoor.rules ddos.rules dns.rules dos.rules exploit.rules \
	finger.rules ftp.rules icmp-info.rules icmp.rules info.rules \
	local.rules misc.rules netbios.rules policy.rules rpc.rules \
	rservices.rules scan.rules shellcode.rules smtp.rules sql.rules \
	telnet.rules virus.rules web-cgi.rules web-coldfusion.rules \
	web-frontpage.rules web-iis.rules web-misc.rules x11.rules
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/snort
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snort
.for f in BUGS CREDITS README README.FLEXRESP README.PLUGINS \
 README.Spade README.Spade.Usage README.csv README.database README.tcpstream \
 README.xml NEWS RULES.SAMPLE USAGE
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/snort
.endfor
	${INSTALL_MAN} ${WRKSRC}/snort.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
