# $NetBSD: Makefile,v 1.13 2003/07/17 21:49:27 grant Exp $

DISTNAME=	logsurfer-1.5b
PKGNAME=	logsurfer-1.5.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cert.dfn.de/pub/tools/audit/logsurfer/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cert.dfn.de/eng/team/wl/logsurf/
COMMENT=	Processes logfiles and performs certain actions

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/etc

.include "../../mk/bsd.pkg.mk"
