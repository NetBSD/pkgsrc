# $NetBSD: Makefile,v 1.8 1998/08/20 15:17:14 tsarna Exp $
# FreeBSD Id: Makefile,v 1.2 1997/10/26 23:56:58 fenner Exp
#

DISTNAME=	logsurfer-1.41
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.fh-rosenheim.de/pub/mirror/cert.dfn/tools/audit/logsurfer/ \
		ftp://ftp.tuwien.ac.at/infosys/security/dfn/tools/audit/logsurfer/ \
		ftp://ftp.uni-magdeburg.de/pub/mirror/ftp.cert.dfn.de/tools/audit/logsurfer/

MAINTAINER=	shanee@rabbit.augusta.de
HOMEPAGE=	http://www.cert.dfn.de/eng/team/wl/logsurf/

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/etc

MANCOMPRESSED=	yes

.include "../../mk/bsd.pkg.mk"
