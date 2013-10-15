# $NetBSD: Makefile,v 1.22 2013/10/15 14:44:42 joerg Exp $

DISTNAME=	milter-regex-1.7
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	jdarrow@NetBSD.org
HOMEPAGE=	http://www.benzedrine.cx/milter-regex.html
COMMENT=	Milter enabling regular expression filtering

USE_TOOLS+=		nroff yacc
INSTALLATION_DIRS=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 sbin

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

.include "../../mk/bsd.prefs.mk"

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wno-unused-const-variable
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/milter-regex ${DESTDIR}${PREFIX}/sbin
.if !empty(MANINSTALL:Mcatinstall)
.  if defined(CATMAN_SECTION_SUFFIX) && !empty(CATMAN_SECTION_SUFFIX:M[Yy][Ee][Ss])
	${INSTALL_DATA} ${WRKSRC}/milter-regex.cat8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/cat8/milter-regex.8
.  else
	${INSTALL_DATA} ${WRKSRC}/milter-regex.cat8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/cat8/milter-regex.0
.  endif
.endif
	${INSTALL_DATA} ${WRKSRC}/milter-regex.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
