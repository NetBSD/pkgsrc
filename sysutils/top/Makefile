# New ports collection makefile for:    top
# Version required:     3.5beta7
# Date created:         25 Sep 1994
# Whom:                 swallace
#
# $NetBSD: Makefile,v 1.10 1998/03/04 07:56:08 hubertf Exp $
# FreeBSD Id: Makefile,v 1.14 1997/04/30 23:49:14 asami Exp
#

DISTNAME=       top-3.5beta7
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.groupsys.com/pub/top/

MAINTAINER=	agc@netbsd.org

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure

MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}" \
		COPY="${COPY}" STRIPFLAG="${STRIPFLAG}" \
		UVM=${UVM}

MAN1=		top.1

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

.include <bsd.port.mk>
