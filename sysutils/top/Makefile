# $NetBSD: Makefile,v 1.19 2000/02/05 07:04:47 wiz Exp $
# FreeBSD Id: Makefile,v 1.14 1997/04/30 23:49:14 asami Exp
#

DISTNAME=       top-3.5beta9
PKGNAME=	top-3.5b9
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.groupsys.com/pub/top/

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.groupsys.com/topinfo/

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONF=			netbsd13
.elif ${OPSYS} == "SunOS"
CONF+=			sunos5
MAKE_ENV+=		CPPFLAGS=
.endif

CONFIGURE_ARGS+=	${CONF}

.if exists(/usr/bin/top)
IGNORE=			"is part of your NetBSD distribution"
.endif

# UVM definition will be pulled in from pkgsrc's mk/bsd.own.mk for now

MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}" \
		COPY="${COPY}" STRIPFLAG="${STRIPFLAG}" \
		UVM=${UVM}

pre-configure:
	${CP} ${FILESDIR}/defaults.${CONF} ${WRKSRC}/.defaults
	${CHMOD} a-x ${WRKSRC}/install

.include "../../mk/bsd.pkg.mk"
