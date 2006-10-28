# $NetBSD: Makefile,v 1.10 2006/10/28 15:17:17 schwarz Exp $

DISTNAME=	deliver-2.1.14
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=deliver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://deliver.sourceforge.net/
COMMENT=	Local mail delivery agent with shell-script control

USE_TOOLS+=	yacc

PKG_SYSCONFSUBDIR=		deliver

PKG_OPTIONS_VAR=		PKG_OPTIONS.deliver
PKG_SUPPORTED_OPTIONS=		deliver-suid

.include "../../mk/bsd.prefs.mk"

.if !empty(LOWER_OPSYS:Mirix5*)
CPPFLAGS+=	-DNO_SYS_TIMEB_H
.endif

.include "../../mk/bsd.options.mk"

pre-configure:
	cd ${WRKSRC};							\
	for FILE in config.h deliver.8 conf/os-netbsd.h; do		\
		${MV} $${FILE} $${FILE}.bak;				\
		${SED} -e 's#@DELIVER_CONF_PREFIX@#${PKG_SYSCONFDIR}#g' \
		       -e 's#@PREFIX@#${PREFIX}#g'			\
		< $${FILE}.bak > $${FILE};				\
	done;								\
	${MV} deliver.8 deliver.1

post-install:
	cd ${WRKSRC};							\
	for FILE in deliver.1 header.1; do				\
		CATFILE=`${BASENAME} $${FILE} .1`.0;			\
		nroff -man $${FILE} > $${CATFILE};			\
		${INSTALL_MAN} $${FILE} ${PREFIX}/man/man1;		\
		${INSTALL_MAN} $${CATFILE} ${PREFIX}/man/cat1;		\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/deliver	\
		${PREFIX}/share/examples/deliver
	cd ${WRKSRC}; \
	${INSTALL_DATA} INSTALL MMDF README SENDMAIL \
		${PREFIX}/share/doc/deliver
	cd ${WRKSRC}/samples; \
	${INSTALL_DATA} README p-aliases s-aliases u-chip u-notify u-vacation \
		${PREFIX}/share/examples/deliver
.if !empty(PKG_OPTIONS:Mdeliver-suid)
	${CHOWN} root ${PREFIX}/bin/deliver
	${CHMOD} u+s ${PREFIX}/bin/deliver
.endif

.include "../../mk/bsd.pkg.mk"
