# $NetBSD: Makefile,v 1.34 2021/06/04 12:31:24 gdt Exp $

DISTNAME=		psmisc-20.1
CATEGORIES=		sysutils
PKGREVISION=		4
#MASTER_SITES=		https://gitlab.com/psmisc/psmisc/-/archive/v22.21/psmisc-v22.21.tar.gz
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=psmisc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gitlab.com/psmisc/psmisc
COMMENT=		Miscellaneous procfs tools: killall, pidof, and pstree
LICENSE=		gnu-gpl-v2

CONFLICTS+=		pstree<=2.16

GNU_CONFIGURE=		yes
PLIST_VARS+=		fuser
LIBS+=			${BUILDLINK_LDADD.getopt}

#
# fuser works only on Linux.
#
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
PLIST.fuser=		yes

.else
SUBST_CLASSES+=		fuser
SUBST_STAGE.fuser=	pre-configure
SUBST_FILES.fuser=	src/Makefile.in doc/Makefile.in
SUBST_SED.fuser=	-e '/^man_MANS =/s/fuser.1//' \
			-e '/^bin_PROGRAMS =/s/fuser//'
.endif

#
# "make install" doesn't install the link from killall -> pidof.
#
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/pidof
	${LN} -f ${DESTDIR}${PREFIX}/bin/killall ${DESTDIR}${PREFIX}/bin/pidof

.include "../../mk/termcap.buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
