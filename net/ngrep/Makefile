# $NetBSD: Makefile,v 1.6 2001/03/05 14:39:08 hubertf Exp $
#

DISTNAME=	ngrep-1.39
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngrep/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://ngrep.sourceforge.net/
COMMENT=	network grep

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pcre
WRKSRC=		${WRKDIR}/ngrep
ALL_TARGET=	ngrep

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	libpcap-0.4:../../net/libpcap

do-configure:
	cd ${WRKSRC}; ./configure --prefix=${PREFIX}
.endif

.include "../../mk/bsd.pkg.mk"
