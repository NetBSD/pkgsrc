# $NetBSD: Makefile,v 1.29 2004/07/11 18:42:26 cube Exp $
# FreeBSD Id: Makefile,v 1.14 1997/04/30 23:49:14 asami Exp
#

DISTNAME=       top-3.5beta9
PKGNAME=	top-3.5b9
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.groupsys.com/pub/top/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.groupsys.com/topinfo/
COMMENT=	The ubiquitous system monitoring utility

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure

NOT_FOR_PLATFORM=	NetBSD-1.6*-* NetBSD-2.*-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONF=			netbsd13
.elif ${OPSYS} == "SunOS"
CONF+=			sunos5
MAKE_ENV+=		CPPFLAGS=
.endif

CONFIGURE_ARGS+=	${CONF}

MAKE_ENV+=	COPY="${COPY}" STRIPFLAG="${_STRIPFLAG_INSTALL}"

pre-configure:
	${CP} ${FILESDIR}/defaults.${CONF} ${WRKSRC}/.defaults
	${CHMOD} a-x ${WRKSRC}/install

.include "../../mk/bsd.pkg.mk"
