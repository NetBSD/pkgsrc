# $NetBSD: Makefile,v 1.56 2012/12/30 11:43:23 tron Exp $

DISTNAME=	milter-greylist-4.2.7
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
EXTRACT_SUFX=	.tgz

OWNER=		tron@NetBSD.org
HOMEPAGE=	http://hcpnet.free.fr/milter-greylist/
COMMENT=	Easy-to-use greylist milter for sendmail
LICENSE=	original-bsd

# yacc rule moving to y.tab.c and renaming
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		YES
BUILD_TARGET=		milter-greylist

USE_TOOLS=		bison lex

RCD_SCRIPTS=		milter-greylist

.include "options.mk"

CONFIGURE_ARGS+=	--with-user=${MILTER_USER}
BUILD_DEFS+=		MILTER_USER MILTER_GROUP VARBASE
FILES_SUBST+=		MILTER_USER=${MILTER_USER:Q}
FILES_SUBST+=		MILTER_GROUP=${MILTER_GROUP:Q}

INSTALLATION_DIRS+=	share/doc/milter-greylist
INSTALLATION_DIRS+=	share/examples/milter-greylist

OWN_DIRS_PERMS+=	${VARBASE}/milter-greylist ${MILTER_USER} ${MILTER_GROUP} 0755

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
	  ${DESTDIR}${PREFIX}/share/doc/milter-greylist
	${INSTALL_DATA} ${WRKSRC}/greylist.conf \
	  ${DESTDIR}${PREFIX}/share/examples/milter-greylist

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
