# $NetBSD: Makefile,v 1.33 2024/02/12 21:06:44 hans Exp $

DISTNAME=	courier-${COURIER_VERSION}
PKGNAME=	${DISTNAME:S/-/tcpd-/}
PKGREVISION=	
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Courier TCP socket and TLS servers
HOMEPAGE=	https://www.courier-mta.org/

CONFLICTS=	courier-imap<4.1.1

USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++

GNU_CONFIGURE_ICONV=	no

.include "../../mail/courier-mta/Makefile.common"

# This package doesn't need to depend on courier-authlib -- just fake
# out the top-level configure script that thinks it needs
# courierauthconfig.
#
CONFIGURE_ENV+=		ac_cv_path_COURIERAUTHCONFIG=${TRUE:Q}

# These are files required by the Courier configure scripts.
WRKSRC_FILES=		courier/courier.c compile config.guess config.sub \
			configure courier-debuild.in depcomp install-sh \
			ltmain.sh missing sysconftool
WRKSRC_FILES+=		Makefile.in courier.spec.in \
			dbobj.h.in dbobj.config.in courier.service.in	\
			courier.sysvinit.in

# These are subdirectories containing libraries used by couriertcpd.
WRKSRC_SUBDIRS=		bdbobj numlib soxwrap md5 random128 \
			rfc822 rfc1035 liblock waitlib tcpd

EXTRACT_ELEMENTS=	${WRKSRC_FILES:S/^/${DISTNAME}\//}
EXTRACT_ELEMENTS+=	${WRKSRC_SUBDIRS:S/^/${DISTNAME}\/libs\//}

BUILD_DIRS=		${WRKSRC_SUBDIRS:S/^/${WRKSRC}\/libs\//}
INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${DOCDIR}

REQD_DIRS=		${DOCDIR}
MAKE_DIRS+=		${COURIER_STATEDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libs/tcpd/couriertcpd			\
		${DESTDIR}${PREFIX}/sbin/couriertcpd
	${INSTALL_MAN} ${WRKSRC}/libs/tcpd/couriertcpd.1			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/couriertcpd.1
	${INSTALL_DATA} ${WRKSRC}/libs/tcpd/couriertcpd.html			\
		${DESTDIR}${DOCDIR}/couriertcpd.html

	${INSTALL_PROGRAM} ${WRKSRC}/libs/tcpd/couriertls			\
		${DESTDIR}${PREFIX}/bin/couriertls
	${INSTALL_MAN} ${WRKSRC}/libs/tcpd/couriertls.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/couriertls.1   
	${INSTALL_DATA} ${WRKSRC}/libs/tcpd/couriertls.html			\
		${DESTDIR}${DOCDIR}/couriertls.html   

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
