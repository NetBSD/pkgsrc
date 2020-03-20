# $NetBSD: Makefile,v 1.9 2020/03/20 11:58:11 nia Exp $

DISTNAME=	uftp-4.10
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://sourceforge.net/projects/uftp-multicast/files/source-tar/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://uftp-multicast.sourceforge.net/
COMMENT=	Encrypted multicast file transfer program
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes
MAKE_FILE=	makefile

MAKE_ENV+=	LIB="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib"

CPPFLAGS.NetBSD+=	-DHAS_GETIFADDRS -DNO_DUAL -DNO_MCAST_JOIN

INSTALLATION_DIRS+=	bin sbin ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} uftp ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_PROGRAM} uftpd ${DESTDIR}${PREFIX}/sbin
	cd ${WRKSRC} && ${INSTALL_PROGRAM} uftpproxyd ${DESTDIR}${PREFIX}/sbin
	cd ${WRKSRC} && ${INSTALL_PROGRAM} uftp_keymgt ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} uftp.1 uftpd.1 uftpproxyd.1 uftp_keymgt.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
