# $NetBSD: Makefile,v 1.14 2009/06/29 22:40:28 joerg Exp $

DISTNAME=	deliver-2.1.14
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=deliver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://deliver.sourceforge.net/
COMMENT=	Local mail delivery agent with shell-script control

PKG_DESTDIR_SUPPORT=	user-destdir

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

pre-configure:
	cd ${WRKSRC};							\
	for FILE in config.h deliver.8 conf/os-netbsd.h; do		\
		${MV} $${FILE} $${FILE}.bak;				\
		${SED} -e 's#@DELIVER_CONF_PREFIX@#${PKG_SYSCONFDIR}#g' \
		       -e 's#@PREFIX@#${PREFIX}#g'			\
		< $${FILE}.bak > $${FILE};				\
	done;								\
	${MV} deliver.8 deliver.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deliver ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/header ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/deliver.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/header.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC}; \
	${INSTALL_DATA} INSTALL MMDF README SENDMAIL \
		${DESTDIR}${PREFIX}/share/doc/deliver
	cd ${WRKSRC}/samples; \
	${INSTALL_DATA} README p-aliases s-aliases u-chip u-notify u-vacation \
		${DESTDIR}${PREFIX}/share/examples/deliver

.include "../../mk/bsd.pkg.mk"
