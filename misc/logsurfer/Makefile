# $NetBSD: Makefile,v 1.6 1998/04/15 10:38:36 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/10/26 23:56:58 fenner Exp
#

DISTNAME=	logsurfer-1.41
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.fh-rosenheim.de/pub/mirror/cert.dfn/tools/audit/logsurfer/ \
		ftp://ftp.tuwien.ac.at/infosys/security/dfn/tools/audit/logsurfer/ \
		ftp://ftp.uni-magdeburg.de/pub/mirror/ftp.cert.dfn.de/tools/audit/logsurfer/

MAINTAINER=	shanee@rabbit.augusta.de

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/etc

MANCOMPRESSED=	yes
MAN1=		logsurfer.1
MAN4=		logsurfer.conf.4

.include "../../mk/bsd.pkg.mk"
