# $NetBSD: Makefile,v 1.19 2012/10/23 19:50:59 asau Exp $

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
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
LIBS.NetBSD+=		-lrt
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdrecord/dvdrecord ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cdrecord/dvdrecord.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
