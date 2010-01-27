# $NetBSD: Makefile,v 1.19 2010/01/27 17:30:14 joerg Exp $
#

DISTNAME=		tnftpd-20081009
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/tnftp/

MAINTAINER=		lukem@NetBSD.org
COMMENT=		The NetBSD FTP Daemon

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		wu-ftpd-[0-9]*
CONFLICTS+=		kth-krb4-[0-9]*
CONFLICTS+=		lukemftpd-[0-9]*

GNU_CONFIGURE=		YES
MANCOMPRESSED_IF_MANZ=	YES
USE_TOOLS+=		yacc

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

CONF_FILES+=		${EXAMPLEDIR}/ftpd.conf ${PKG_SYSCONFDIR}/ftpd.conf
CONF_FILES+=		${EXAMPLEDIR}/ftpusers ${PKG_SYSCONFDIR}/ftpusers

.include "options.mk"

OPSYSVARS+=		MAKE_ENV
MAKE_ENV.SunOS+=	CPPFLAGS=""

EXAMPLEDIR=		${PREFIX}/share/examples/tnftpd
INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 \
			${EXAMPLEDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/tnftpd ${DESTDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/src/ftpd.conf.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/ftpd.conf.5
	${INSTALL_MAN} ${WRKSRC}/src/ftpusers.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/ftpusers.5
	${INSTALL_MAN} ${WRKSRC}/src/tnftpd.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/tnftpd.8
	${INSTALL_DATA} ${WRKSRC}/examples/ftpd.conf ${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/ftpusers ${DESTDIR}${EXAMPLEDIR}

.include "../../mk/bsd.pkg.mk"
