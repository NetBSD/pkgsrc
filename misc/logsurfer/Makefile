# $NetBSD: Makefile,v 1.10 2001/02/17 18:09:13 wiz Exp $
# FreeBSD Id: Makefile,v 1.2 1997/10/26 23:56:58 fenner Exp
#

DISTNAME=	logsurfer-1.5
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cert.dfn.de/pub/tools/audit/logsurfer/

MAINTAINER=	chris@cjones.org
HOMEPAGE=	http://www.cert.dfn.de/eng/team/wl/logsurf/
COMMENT=	Processes logfiles and performs certain actions

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/etc

.include "../../mk/bsd.pkg.mk"
