# $NetBSD: Makefile,v 1.14 1998/08/20 15:17:27 tsarna Exp $
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

MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}" \
		COPY="${COPY}" STRIPFLAG="${STRIPFLAG}" \
		UVM=${UVM}

OPSYS!= uname -s
.if (${OPSYS} == "FreeBSD")
OSVERSION!=	sysctl -n kern.osreldate
.if ${OSVERSION} >= 221002
BROKEN=		"top is included in FreeBSD version 221002 or later"
.endif
CONFIGURE_ARGS+=		freebsd2
.elif (${OPSYS} == "NetBSD")
CONFIGURE_ARGS+=		netbsd13
.endif

pre-configure:
	${CP} ${FILESDIR}/defaults ${WRKSRC}/.defaults
.if (${OPSYS} == "FreeBSD")
	${CP} ${FILESDIR}/m_freebsd2.* ${WRKSRC}/machine
.endif
	chmod a-x ${WRKSRC}/install

.include "../../mk/bsd.pkg.mk"
