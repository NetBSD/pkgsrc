# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 14:06:05 wiz Exp $

DISTNAME=	deliver-2.1.14
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=deliver/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://deliver.sourceforge.net/
COMMENT=	Local mail delivery agent with shell-script control

.include "../../mk/bsd.prefs.mk"

# Deliver prefers to be installed suid root, but by default we don't do that.
DELIVER_SUID?=	NO

# Use DELIVER_CONF_PREFIX from /etc/mk.conf, if defined.
# If this specifies a directory that will contain files other than deliver's
# delivery files, you may also want to add a suffix like "deliver.", to
# identify the "sys", "post", and "err" delivery files as owned by deliver.
DELIVER_CONF_PREFIX?=	${PREFIX}/etc/deliver/

post-patch:
	cd ${WRKSRC};							\
	for FILE in config.h deliver.8; do				\
		${MV} $${FILE} $${FILE}.bak;				\
		${SED} -e 's#@DELIVER_CONF_PREFIX@#${DELIVER_CONF_PREFIX}#g' \
		< $${FILE}.bak > $${FILE};				\
	done;								\
	${MV} deliver.8 deliver.1

post-install:
	cd ${WRKSRC};							\
	for FILE in deliver.1 header.1; do				\
		CATFILE=`${BASENAME} $${FILE} .1`.0;			\
		${NROFF} -man $${FILE} > $${CATFILE};			\
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
.if defined(DELIVER_SUID) && ${DELIVER_SUID} == YES
	${CHOWN} root ${PREFIX}/bin/deliver
	${CHMOD} u+s ${PREFIX}/bin/deliver
.endif

.include "../../mk/bsd.pkg.mk"
.include <bsd.man.mk>
