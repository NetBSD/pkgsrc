# $NetBSD: Makefile,v 1.39 2009/01/19 06:16:38 obache Exp $

DISTNAME=	milter-greylist-4.0.1
PKGREVISION=	1
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
CONFIGURE_ARGS+=	--with-user=smmsp

BUILD_TARGET=		milter-greylist

PKG_GROUPS=		smmsp
PKG_USERS=		smmsp:smmsp
PKG_GECOS.smmsp=	Sendmail Message Submission Program

RCD_SCRIPTS=	milter-greylist

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/milter-greylist
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/milter-greylist
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/milter-greylist
	${INSTALL_DATA} ${WRKSRC}/greylist.conf \
	  ${DESTDIR}${PREFIX}/share/examples/milter-greylist

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
