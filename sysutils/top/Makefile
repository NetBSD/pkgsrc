# $NetBSD: Makefile,v 1.16 1999/02/15 04:36:31 simonb Exp $
# FreeBSD Id: Makefile,v 1.14 1997/04/30 23:49:14 asami Exp
#

DISTNAME=       top-3.5beta7
PKGNAME=	top-3.5b7
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.groupsys.com/pub/top/

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.groupsys.com/topinfo/

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS+=	netbsd13

.if exists(/usr/bin/top)
IGNORE=			"is part of your NetBSD distribution"
.endif

# UVM definition will be pulled in from pkgsrc's mk/bsd.own.mk for now

MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}" \
		COPY="${COPY}" STRIPFLAG="${STRIPFLAG}" \
		UVM=${UVM}

pre-configure:
	${CP} ${FILESDIR}/defaults ${WRKSRC}/.defaults
	chmod a-x ${WRKSRC}/install

.include "../../mk/bsd.pkg.mk"
