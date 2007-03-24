# $NetBSD: Makefile,v 1.18 2007/03/24 19:21:28 joerg Exp $

DISTNAME=	logsurfer-1.5b
PKGNAME=	logsurfer-1.6.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.dfn-cert.de/pub/tools/audit/logsurfer/

PATCH_SITES=	http://www.crypt.gen.nz/logsurfer/
PATCHFILES=	logsurfer-15b-16b.patch

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dfn-cert.de/eng/logsurf/
COMMENT=	Processes logfiles and performs certain actions

PATCH_DIST_STRIP.logsurfer-15b-16b.patch=	-p2

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

BUILD_DEFS+=	VARBASE

EGDIR=		${PREFIX}/share/examples/logsurfer

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man4 ${EGDIR}

post-install:
	${MKDIR} ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/start-mail/start-mail ${EGDIR}/start-mail

.include "../../mk/bsd.pkg.mk"
