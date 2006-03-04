# $NetBSD: Makefile,v 1.11 2006/03/04 21:29:01 jlam Exp $

DISTNAME=	dbench-3.03
PKGREVISION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	http://samba.org/ftp/tridge/dbench/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://samba.org/ftp/tridge/dbench/README
COMMENT=	Simulation of the Ziff-Davis netbench benchmark

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	DB_LDFLAGS="-lrt" TB_LDFLAGS="-lsocket -lnsl"
.endif

.include "../../mk/bsd.pkg.mk"
