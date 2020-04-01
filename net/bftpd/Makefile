# $NetBSD: Makefile,v 1.23 2020/04/01 10:01:29 nia Exp $

DISTNAME=	bftpd-5.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bftpd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bftpd.sourceforge.net/
COMMENT=	Small and fast FTP server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

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

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 share/examples/bftpd

BUILD_DEFS+=		VARBASE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bftpd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/bftpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/bftpd.conf ${DESTDIR}${PREFIX}/share/examples/bftpd

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
