# $NetBSD: Makefile,v 1.4 2000/07/18 18:42:48 tron Exp $

DISTNAME=	rp-pppoe-2.0
CATEGORIES=	net
MASTER_SITES=	http://www.roaringpenguin.com/pppoe/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://home.sprynet.com/~minaret/pppoe/

.if !defined(CHECK_PPPD_DEPENDS)
DEPENDS!=	${MAKE} CHECK_PPPD_DEPENDS=1 ${MAKEFLAGS} pppd-depend
.endif

CONFLICTS+=	mouse_pppoe-*

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PPPD=${PPPD}

post-install:
	${INSTALL_DATA} ${WRKSRC}/pppoe.conf ${PREFIX}/share/doc/rp-pppoe

.include "../../mk/bsd.pkg.mk"

BASE_PPPD=	/usr/sbin/pppd
PPPD_VERSION!=	${BASE_PPPD} --version 2>&1 | \
		${SED} -e 's/ patch level /\./' -e 's/.* //' | \
		${AWK} -F. '{printf("%d\n",$$1*1000000+$$2*1000+$$3)}'

.if ${PPPD_VERSION} < 2003010
PPPD=		${LOCALBASE}/sbin/pppd

pppd-depend:
		@${ECHO} "ppp>=2.3.10:../ppp"
.else
PPPD=		${BASE_PPPD}

pppd-depend:
		@${ECHO} ""
.endif
