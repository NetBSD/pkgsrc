# $NetBSD: Makefile,v 1.13 2008/01/18 05:08:40 tnn Exp $

DISTNAME=	courier-${COURIER_VERSION}
PKGNAME=	${DISTNAME:S/-/tcpd-/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@pkgsrc.org
COMMENT=	Courier TCP socket and TLS servers
HOMEPAGE=	http://www.courier-mta.org/

CONFLICTS=	courier-imap<4.11

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

PKG_OPTIONS_VAR=	PKG_OPTIONS.couriertcpd
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

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
			dbobj.h.in dbobj.config.in courier.sysvinit.in

# These are subdirectories containing libraries used by couriertcpd.
WRKSRC_SUBDIRS=		bdbobj numlib soxwrap md5 random128 rfc1035	\
			liblock waitlib tcpd

EXTRACT_ELEMENTS=	${WRKSRC_FILES:S/^/${DISTNAME}\//}
EXTRACT_ELEMENTS+=	${WRKSRC_SUBDIRS:S/^/${DISTNAME}\//}

BUILD_DIRS=		${WRKSRC_SUBDIRS:S/^/${WRKSRC}\//}
INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${DOCDIR}

REQD_DIRS=		${DOCDIR}
MAKE_DIRS+=		${COURIER_STATEDIR}

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpd/couriertcpd			\
		${PREFIX}/sbin/couriertcpd
	${INSTALL_MAN} ${WRKSRC}/tcpd/couriertcpd.1			\
		${PREFIX}/${PKGMANDIR}/man1/couriertcpd.1
	${INSTALL_DATA} ${WRKSRC}/tcpd/couriertcpd.html			\
		${DOCDIR}/couriertcpd.html

	${INSTALL_PROGRAM} ${WRKSRC}/tcpd/couriertls			\
		${PREFIX}/bin/couriertls
	${INSTALL_MAN} ${WRKSRC}/tcpd/couriertls.1			\
		${PREFIX}/${PKGMANDIR}/man1/couriertls.1
	${INSTALL_DATA} ${WRKSRC}/tcpd/couriertls.html			\
		${DOCDIR}/couriertls.html

.include "../../mk/bsd.pkg.mk"
