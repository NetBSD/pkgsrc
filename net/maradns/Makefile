# $NetBSD: Makefile,v 1.27 2015/09/26 07:40:25 wen Exp $

DISTNAME=	maradns-2.0.13
CATEGORIES=	net
MASTER_SITES=	http://www.maradns.org/download/2.0/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://www.maradns.org/
COMMENT=	Secure DNS server for *NIX systems
LICENSE=	2-clause-bsd

USE_TOOLS+=	awk:build

HAS_CONFIGURE=		yes
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes
MAKE_ENV+=		LANGUAGE="en"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 \
			${PKGMANDIR}/man8 sbin share/examples

.include "../../mk/pthread.buildlink3.mk"
LDFLAGS+=	${PTHREAD_LIBS}

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	pre-configure
SUBST_VARS.sysconf=	PKG_SYSCONFDIR
SUBST_FILES.sysconf=	parse/ParseMaraRc.c MaraDns.h deadwood-3.2.09/src/DwMain.c

.include "options.mk"

post-install:
	cd ${DESTDIR}${PREFIX}/share/doc/maradns && ${MV} examples ../../examples/maradns

.include "../../mk/bsd.pkg.mk"
