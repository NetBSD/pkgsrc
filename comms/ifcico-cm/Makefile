# $NetBSD: Makefile,v 1.2 1998/12/21 15:45:20 tv Exp $
#

DISTNAME=	ifcico-3.0.cm.alpha-4.0
PKGNAME=	ifcico-cm-3.0.4.0.1
CATEGORIES=	comms
MASTER_SITES=	http://www.cosy.sbg.ac.at/~cmeer/files/

MAINTAINER=	tv@netbsd.org	# aka "Todd Vierling" @ 1:396/1.5
HOMEPAGE=	http://www.cosy.sbg.ac.at/~cmeer/ifcico/

NO_CDROM=	"extremely limited usefulness to the general public"

post-build:
	cd ${WRKSRC}/contrib/iftelnetd && ${MAKE} iftelnetd
	cd ${WRKSRC}/contrib/fdpass && ${LINK.c} -o fdpass fdpass.c

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/ifmail ${PREFIX}/etc/ifmail/inouttabs
	${INSTALL_DATA} ${WRKSRC}/misc/config ${PREFIX}/etc/ifmail/config.dist
	${INSTALL_DATA} ${WRKSRC}/misc/config-global ${PREFIX}/etc/ifmail/
	cd ${WRKSRC}/misc/inouttabs && ${INSTALL_DATA} fidom2iso ibmpc-latin1 \
		iso2fidom latin1-ibmpc outaltkoi8 outkoi8alt \
		${PREFIX}/etc/ifmail/inouttabs/
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/iftelnetd/iftelnetd ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/fdpass/fdpass ${PREFIX}/sbin/
	cd ${WRKSRC}/ifcico && ${INSTALL_MAN} ifcico.8 ifindex.8 ifinfo.8 \
		ifreq.8 ifroute.8 ifstat.8 nlpatch.8 ${PREFIX}/man/man8/

.include "../../mk/bsd.pkg.mk"
