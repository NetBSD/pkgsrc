# $NetBSD: Makefile,v 1.11 2002/10/05 06:11:30 tron Exp $

DISTNAME=	logsurfer-1.5b
PKGNAME=	logsurfer-1.5.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cert.dfn.de/pub/tools/audit/logsurfer/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cert.dfn.de/eng/team/wl/logsurf/
COMMENT=	Processes logfiles and performs certain actions

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/etc

.include "../../mk/bsd.pkg.mk"
