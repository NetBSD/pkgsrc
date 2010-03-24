# $NetBSD: Makefile,v 1.21 2010/03/24 14:12:44 lukem Exp $
#

DISTNAME=		tnftpd-20100324
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

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

CONF_FILES+=		${EXAMPLEDIR}/ftpd.conf ${PKG_SYSCONFDIR}/ftpd.conf
CONF_FILES+=		${EXAMPLEDIR}/ftpusers ${PKG_SYSCONFDIR}/ftpusers

.include "options.mk"

OPSYSVARS+=		MAKE_ENV
MAKE_ENV.SunOS+=	CPPFLAGS=""

EXAMPLEDIR=		${PREFIX}/share/examples/tnftpd
INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 \
			${EXAMPLEDIR}

.include "../../mk/bsd.pkg.mk"
