# New ports collection makefile for:	scotty
# Version required:	2.1.6
# Date created:		18 Februar 1995
# Whom:			Gennady Sorokopud <gena@netvision.net.il>
#
# $NetBSD: Makefile,v 1.6 1998/03/07 22:11:19 hubertf Exp $
# FreeBSD Id: Makefile,v 1.21 1997/08/27 23:01:53 cwt Exp
#

DISTNAME=	scotty-2.1.8
CATEGORIES=	net tk80
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	phk@freebsd.org

LIB_DEPENDS=	tk80.1.:${PORTSDIR}/x11/tk80

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+= --with-tcl-config=${PREFIX}/lib/tcl8.0 \
		--with-tk-config=${PREFIX}/lib/tk8.0

WRKSRC=${WRKDIR}/${DISTNAME}/unix
MAN1=		tkined.1 scotty.1
MAN8=		ntping.8 straps.8
MANN=		Tnm.n cmip.n dns.n gdmo.n http.n icmp.n ined.n job.n \
		mib.n msqltcl.n netdb.n ntp.n rpc.n snmp.n sunrpc.n \
		syslog.n udp.n
PLIST=		${PKGDIR}/PLIST.tmp

pre-install:
	@cd ${WRKSRC};make sinstall
	@${CP} ${WRKSRC}/../tnm/ntping/ntping.8 ${WRKSRC}/../doc
	@sed "s,@NETBSD_VERSION@,$$(uname -m)-$$(uname)-$$(uname -r)," ${PKGDIR}/PLIST >${PLIST}.tmp
PLIST_SRC=${PLIST}.tmp

pre-clean:
	@${RM} -f ${PKGDIR}/PLIST.tmp

.include <bsd.port.mk>
