# $NetBSD: Makefile,v 1.25 2002/12/07 02:39:05 schmonz Exp $
# FreeBSD Id: Makefile,v 1.14 1997/04/30 23:49:14 asami Exp
#

DISTNAME=       top-3.5beta9
PKGNAME=	top-3.5b9
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.groupsys.com/pub/top/

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.groupsys.com/topinfo/
COMMENT=	The ubiquitous system monitoring utility

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONF=			netbsd13
.elif ${OPSYS} == "SunOS"
CONF+=			sunos5
MAKE_ENV+=		CPPFLAGS=
.endif

CONFIGURE_ARGS+=	${CONF}

.if exists(/usr/bin/top)
PKG_SKIP_REASON=	"${PKGNAME} is part of your ${OPSYS} distribution"
.endif

MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}" \
		COPY="${COPY}" STRIPFLAG="${_STRIPFLAG_INSTALL}"

pre-configure:
	${CP} ${FILESDIR}/defaults.${CONF} ${WRKSRC}/.defaults
	${CHMOD} a-x ${WRKSRC}/install

.include "../../mk/bsd.pkg.mk"
