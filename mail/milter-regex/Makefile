# $NetBSD: Makefile,v 1.15 2007/12/21 22:54:57 joerg Exp $

DISTNAME=	milter-regex-1.6
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	jdarrow@NetBSD.org
HOMEPAGE=	http://www.benzedrine.cx/milter-regex.html
COMMENT=	Milter enabling regular expression filtering

USE_TOOLS+=		yacc
INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

PKG_GROUPS=		smmsp
PKG_USERS=		smmsp:smmsp
PKG_GECOS.smmsp=	Sendmail Message Submission Program

RCD_SCRIPTS=	milter-regex

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	do-configure
SUBST_FILES.etc=	milter-regex.8 milter-regex.c
SUBST_SED.etc=		-e 's|/etc|${PKG_SYSCONFDIR}|g'

SUBST_CLASSES+=		var
SUBST_STAGE.var=	do-configure
SUBST_FILES.var=	milter-regex.8 milter-regex.c
SUBST_SED.var=		-e 's|/var/spool|${VARBASE}|g'

# Work arround to avoid naming clash between the source directory
# and our "rc.d" script.
post-extract:
	${MV} ${WRKDIR}/${PKGBASE} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/milter-regex ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/milter-regex.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
