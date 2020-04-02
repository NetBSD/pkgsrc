# $NetBSD: Makefile,v 1.27 2020/04/02 09:35:22 nia Exp $

DISTNAME=		tnftpd-20190602
CATEGORIES=		net
MASTER_SITES=		https://cdn.netbsd.org/pub/NetBSD/misc/tnftp/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		The NetBSD FTP Daemon
LICENSE=		2-clause-bsd

CONFLICTS=		wu-ftpd-[0-9]*
CONFLICTS+=		kth-krb4-[0-9]*
CONFLICTS+=		lukemftpd-[0-9]*
CONFLICTS=		man-pages-[0-9]*

GNU_CONFIGURE=		YES
MANCOMPRESSED_IF_MANZ=	YES
USE_LIBTOOL=		yes
USE_TOOLS+=		yacc

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

CONF_FILES+=		${EXAMPLEDIR}/ftpd.conf ${PKG_SYSCONFDIR}/ftpd.conf
CONF_FILES+=		${EXAMPLEDIR}/ftpusers ${PKG_SYSCONFDIR}/ftpusers

.include "options.mk"

MAKE_ENV.SunOS+=	CPPFLAGS=""

EXAMPLEDIR=		${PREFIX}/share/examples/tnftpd
INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 \
			${EXAMPLEDIR}

.include "../../mk/bsd.pkg.mk"
