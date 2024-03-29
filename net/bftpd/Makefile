# $NetBSD: Makefile,v 1.30 2022/12/03 10:41:15 nros Exp $

DISTNAME=	bftpd-6.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bftpd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bftpd.sourceforge.net/
COMMENT=	Small and fast FTP server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

WRKSRC=		${WRKDIR}/bftpd

CONF_FILES=	${PREFIX}/share/examples/bftpd/bftpd.conf \
		${PKG_SYSCONFDIR}/bftpd.conf

CONFIGURE_ARGS+=	--enable-libz

SUBST_CLASSES+=		varbase
SUBST_STAGE.varbase=	post-configure
SUBST_FILES.varbase=	bftpd.conf
SUBST_SED.varbase=	-e 's|/var/|${VARBASE}/|g'

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	post-configure
SUBST_FILES.sysconf=	mypaths.h bftpd.8
SUBST_SED.sysconf=	-e 's|PREFIX"/etc/|"${PKG_SYSCONFDIR}/|g'
SUBST_SED.sysconf+=	-e 's|normally /etc/|normally ${PKG_SYSCONFDIR}/|g'

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 share/examples/bftpd

BUILD_DEFS+=		VARBASE

OWN_DIRS+=		${VARBASE}/run/bftpd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bftpd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/bftpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/bftpd.conf ${DESTDIR}${PREFIX}/share/examples/bftpd

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
