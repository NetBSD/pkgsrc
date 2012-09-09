# $NetBSD: Makefile,v 1.15 2012/09/09 18:28:07 cheusov Exp $

DISTNAME=	deliver-2.1.14
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=deliver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://deliver.sourceforge.net/
COMMENT=	Local mail delivery agent with shell-script control

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		avenger-[0-9]*

USE_TOOLS+=	yacc

PKG_SYSCONFSUBDIR=		deliver

PKG_OPTIONS_VAR=		PKG_OPTIONS.deliver
PKG_SUPPORTED_OPTIONS=		deliver-suid

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1 \
	share/doc/deliver share/examples/deliver

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MIRIX-5*)
CPPFLAGS+=	-DNO_SYS_TIMEB_H
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdeliver-suid)
SPECIAL_PERMS+=		bin/deliver ${SETUID_ROOT_PERMS}
.endif

SUBST_CLASSES+=			sources
SUBST_STAGE.sources=		post-patch
SUBST_MESSAGE.sources=		Fixing source code.
SUBST_FILES.sources=		config.h deliver.8 conf/os-netbsd.h
SUBST_SED.sources=		-e 's,@DELIVER_CONF_PREFIX@,$(PKG_SYSCONFDIR),g'
SUBST_SED.sources+=		-e 's,@PREFIX@,$(PREFIX),g'

pre-configure:
	set -e; cd ${WRKSRC};							\
	${MV} deliver.8 deliver.1

do-install:
	set -e; \
	${INSTALL_PROGRAM} ${WRKSRC}/deliver ${DESTDIR}${PREFIX}/bin; \
	${INSTALL_PROGRAM} ${WRKSRC}/header ${DESTDIR}${PREFIX}/bin; \
	${INSTALL_MAN} ${WRKSRC}/deliver.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	${INSTALL_MAN} ${WRKSRC}/header.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	cd ${WRKSRC}; \
	${INSTALL_DATA} INSTALL MMDF README SENDMAIL \
		${DESTDIR}${PREFIX}/share/doc/deliver; \
	cd ${WRKSRC}/samples; \
	${INSTALL_DATA} README p-aliases s-aliases u-chip u-notify u-vacation \
		${DESTDIR}${PREFIX}/share/examples/deliver

.include "../../mk/bsd.pkg.mk"
