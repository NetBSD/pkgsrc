# $NetBSD: Makefile,v 1.16 2006/12/07 12:51:36 obache Exp $

DISTNAME=	logsurfer-1.5b
PKGNAME=	logsurfer-1.6.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cert.dfn.de/pub/tools/audit/logsurfer/

PATCH_SITES=	http://www.crypt.gen.nz/logsurfer/
PATCHFILES=	logsurfer-15b-16b.patch

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cert.dfn.de/eng/logsurf/
COMMENT=	Processes logfiles and performs certain actions

PATCH_DIST_STRIP.logsurfer-15b-16b.patch=	-p2

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

BUILD_DEFS+=	VARBASE

.include "../../mk/bsd.pkg.mk"
