# $NetBSD: Makefile,v 1.40 2009/03/08 15:54:26 tron Exp $

DISTNAME=	milter-greylist-4.0.1
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
EXTRACT_SUFX=	.tgz

OWNER=		tron@NetBSD.org
HOMEPAGE=	http://hcpnet.free.fr/milter-greylist/
COMMENT=	Easy-to-use greylist milter for sendmail

PKG_DESTDIR_SUPPORT=	user-destdir

# yacc rule moving to y.tab.c and renaming
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		YES
BUILD_TARGET=		milter-greylist

RCD_SCRIPTS=		milter-greylist

.include "options.mk"

CONFIGURE_ARGS+=	--with-user=${MILTER_USER}
BUILD_DEFS+=		MILTER_USER
FILES_SUBST+=		MILTER_USER=${MILTER_USER:Q}

INSTALLATION_DIRS+=	share/doc/milter-greylist
INSTALLATION_DIRS+=	share/examples/milter-greylist

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
	  ${DESTDIR}${PREFIX}/share/doc/milter-greylist
	${INSTALL_DATA} ${WRKSRC}/greylist.conf \
	  ${DESTDIR}${PREFIX}/share/examples/milter-greylist

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
