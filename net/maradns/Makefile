# $NetBSD: Makefile,v 1.24 2012/02/20 14:08:07 cheusov Exp $

DISTNAME=	maradns-1.4.06
CATEGORIES=	net
MASTER_SITES=	http://www.maradns.org/download/1.4/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://www.maradns.org/
COMMENT=	Secure DNS server for *NIX systems

USE_TOOLS+=	awk:build

PKG_DESTDIR_SUPPORT=	user-destdir

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
SUBST_FILES.sysconf=	parse/ParseMaraRc.c

post-install:
	cd ${DESTDIR}${PREFIX}/share/doc/maradns && ${MV} examples ../../examples/maradns

.include "../../mk/bsd.pkg.mk"
