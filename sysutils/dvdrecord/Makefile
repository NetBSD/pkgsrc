# $NetBSD: Makefile,v 1.17 2008/03/08 11:14:11 obache Exp $

DISTNAME=	dvdrtools-${VERSION}
PKGNAME=	${DISTNAME:S/dvdrtools/dvdrecord/}
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://freesoftware.fsf.org/download/dvdrtools/dvdrtools.pkg/${VERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/dvdrtools/
COMMENT=	This program allows you to create DVDs on a DVD-Recorder

VERSION=	0.1.5

GNU_CONFIGURE=		yes
# Override wrong usage of AC_DEFINE_UNQUOTED:
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
LIBS.SunOS+=		-lsocket
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
LIBS.NetBSD+=		-lrt
.endif

do-install:
	cd ${WRKSRC}/cdrecord;						\
		${INSTALL_PROGRAM} dvdrecord ${PREFIX}/bin;		\
		${INSTALL_MAN} dvdrecord.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
