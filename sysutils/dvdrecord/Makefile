# $NetBSD: Makefile,v 1.21 2020/01/18 23:35:16 rillig Exp $

DISTNAME=	dvdrtools-${VERSION}
PKGNAME=	${DISTNAME:S/dvdrtools/dvdrecord/}
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://freesoftware.fsf.org/download/dvdrtools/dvdrtools.pkg/${VERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/dvdrtools/
COMMENT=	This program allows you to create DVDs on a DVD-Recorder

VERSION=	0.1.5

GNU_CONFIGURE=		yes
# Override wrong usage of AC_DEFINE_UNQUOTED:
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
LIBS.SunOS+=		-lsocket
LIBS.Darwin+=		-framework IOKit -framework CoreFoundation
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
