# $NetBSD: Makefile,v 1.32 2020/05/21 19:21:17 rillig Exp $

DISTNAME=	courier-${COURIER_VERSION}
PKGNAME=	${DISTNAME:S/-/tcpd-/}
PKGREVISION=	9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Courier TCP socket and TLS servers
HOMEPAGE=	https://www.courier-mta.org/

CONFLICTS=	courier-imap<4.1.1

USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++

.include "../../mail/courier-mta/Makefile.common"

# This package doesn't need to depend on courier-authlib -- just fake
# out the top-level configure script that thinks it needs
# courierauthconfig.
#
CONFIGURE_ENV+=		ac_cv_path_COURIERAUTHCONFIG=${TRUE:Q}

# These are files required by the Courier configure scripts.
WRKSRC_FILES=		courier/courier.c config.guess config.sub	\
			configure depcomp install-sh ltmain.sh missing	\
			sysconftool
WRKSRC_FILES+=		Makefile.in courier.spec.in courier.lpspec.in	\
			dbobj.h.in dbobj.config.in courier.service.in	\
			courier.sysvinit.in

# These are subdirectories containing libraries used by couriertcpd.
WRKSRC_SUBDIRS=		bdbobj numlib soxwrap md5 random128 unicode	\
			rfc822 rfc1035 liblock waitlib tcpd

EXTRACT_ELEMENTS=	${WRKSRC_FILES:S/^/${DISTNAME}\//}
EXTRACT_ELEMENTS+=	${WRKSRC_SUBDIRS:S/^/${DISTNAME}\//}

BUILD_DIRS=		${WRKSRC_SUBDIRS:S/^/${WRKSRC}\//}
INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${DOCDIR}

REQD_DIRS=		${DOCDIR}
MAKE_DIRS+=		${COURIER_STATEDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpd/couriertcpd			\
		${DESTDIR}${PREFIX}/sbin/couriertcpd
	${INSTALL_MAN} ${WRKSRC}/tcpd/couriertcpd.1			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/couriertcpd.1
	${INSTALL_DATA} ${WRKSRC}/tcpd/couriertcpd.html			\
		${DESTDIR}${DOCDIR}/couriertcpd.html

.include "../../mk/bsd.pkg.mk"
