# $NetBSD: Makefile,v 1.3 2004/03/31 09:39:24 sketch Exp $
#

DISTNAME=		chkrootkit
PKGNAME=		${DISTNAME}-0.43
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.pangeia.com.br/pub/seg/pac/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.chkrootkit.org/
COMMENT=		Locally checks for signs of a rootkit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
DIST_SUBDIR=		${PKGNAME}
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes

PROGRAMS=	chkdirs chklastlog chkproc chkwtmp ifpromisc strings-static

.include "../../mk/compiler.mk"

.if ${OPSYS} == "SunOS"
PROGRAMS+=	check_wtmpx
PLIST_SUBST+=	WTMPX=""
CFLAGS+=	-DSOLARIS2
LDFLAGS+=	-lsocket
.  if empty(CC_VERSION:Mgcc-*)
MAKE_ENV+=	STATIC="-B static"
.  else
MAKE_ENV+=	STATIC="-static"
.  endif
.else
PLIST_SUBST+=	WTMPX="@comment "
MAKE_ENV+=	STATIC="-static"
.endif

INSTALLATION_DIRS+=	bin

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PROGRAMS} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
