# $NetBSD: Makefile,v 1.1.1.1 2003/06/05 01:00:45 jschauma Exp $
#

DISTNAME=	waste-source
PKGNAME=	waste-1.0
CATEGORIES=	net
# AOL pulled the plug on Nullsoft
# MASTER_SITES=	http://www.nullsoft.com/free/waste/
# HOMEPAGE=	http://www.nullsoft.com/free/waste/
MASTER_SITES=	http://www.dhorrocks2003.pwp.blueyonder.co.uk/ \
		http://www.blibbleblobble.co.uk/Misc/ \
		http://edwards.servehttp.com:969/waste/ \
		http://www.cleanstick.org/jon/junk/ \
		http://www.samsimpson.com/ \
		http://cyber.law.harvard.edu/blogs/gems/home/ \
		http://www.sifnt.net/ \
		ftp://ftp.wiresec.net/waste/ \
		http://slackerbitch.free.fr/waste/

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://www.dhorrocks2003.pwp.blueyonder.co.uk/
COMMENT=	secure file sharing network

WRKSRC=		${WRKDIR}/waste

RESTRICTED=     Unclear legal status: AOL claims Nullsoft did not \
		release the software at all, while others regard it as \
		licensed under the GPL

NO_SRC_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wastesrv ${PREFIX}/sbin/wastesrv
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/waste
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/waste

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
